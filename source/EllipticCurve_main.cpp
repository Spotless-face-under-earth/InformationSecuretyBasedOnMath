#include"source.h"
#include <iostream>
using namespace std;
int main()
{
	int a, b, p;
	cout << "请输入：a,b,p构成Z"<< "上的椭圆曲线。" << endl;
	cin >> a  >>b >> p;
	if (isEllipticCurve(a, b, p)) {
		cout << "y^2≡x^3+" << a << "x+" << b <<" (mod "<<p<<")"<< endl;
		EllipticCurve mainElli = EllipticCurve(a, b, p);
		int ppx, ppy;
		cout << "输入点P：";
		cin >> ppx >> ppy;Node pointp(ppx,ppy);
		if (mainElli.isOnCurve(pointp))
		{
			cout << "输入点在椭圆曲线上。" <<endl<<"输入点Q：";
			cin >> ppx >> ppy;
			Node pointq(ppx,ppy);
			if (mainElli.isOnCurve(pointq))
			{
				cout << "输入点在椭圆曲线上。" << endl;
				cout << "P+Q=";
				Node pointm=mainElli.addP(pointp,pointq);
				cout << " (" << pointm.xp << "," << pointm.yp << ") " << endl;
				cout << "请输入倍加值m，计算mP: ";
				int m;cin >> m;
				Node pointn = mainElli.multiAddP(m, pointp);
				if(pointn.xp==-1)
				cout << "mP= O " << endl;
				else
				cout << "mP= (" << pointn.xp << "," << pointn.yp << ") " << endl;
				int order = mainElli.getOrdP(pointp);
				if (order >1) {
					cout << "ord(P)=" << order << endl;
					deque<Node> ou;int ouN;
					ou = mainElli.getP();ouN = mainElli.getPNum();
					cout << "椭圆曲线阶数#E= " << ouN << "   分别为： ";
					while (!ou.empty())
					{
						ou.front().output();
						ou.pop_front();
					}
					cout <<"O " << endl;
				}
				else {
					cout << "Error ord(P)!" << endl;
				}
			}
			else {
				cout << "输入点不在椭圆曲线上！" << endl;
			}
		}
		else {
			cout << "输入点不在椭圆曲线上！" << endl;
		}
	}
	else {
		cout << "输入不能构成椭圆曲线！" << endl;
	}
	system("pause");
}