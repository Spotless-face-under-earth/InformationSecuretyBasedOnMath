#include"source.h"
#include <iostream>
using namespace std;
int main()
{
	int a, b, p;
	cout << "�����룺a,b,p����Z"<< "�ϵ���Բ���ߡ�" << endl;
	cin >> a  >>b >> p;
	if (isEllipticCurve(a, b, p)) {
		cout << "y^2��x^3+" << a << "x+" << b <<" (mod "<<p<<")"<< endl;
		EllipticCurve mainElli = EllipticCurve(a, b, p);
		int ppx, ppy;
		cout << "�����P��";
		cin >> ppx >> ppy;Node pointp(ppx,ppy);
		if (mainElli.isOnCurve(pointp))
		{
			cout << "���������Բ�����ϡ�" <<endl<<"�����Q��";
			cin >> ppx >> ppy;
			Node pointq(ppx,ppy);
			if (mainElli.isOnCurve(pointq))
			{
				cout << "���������Բ�����ϡ�" << endl;
				cout << "P+Q=";
				Node pointm=mainElli.addP(pointp,pointq);
				cout << " (" << pointm.xp << "," << pointm.yp << ") " << endl;
				cout << "�����뱶��ֵm������mP: ";
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
					cout << "��Բ���߽���#E= " << ouN << "   �ֱ�Ϊ�� ";
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
				cout << "����㲻����Բ�����ϣ�" << endl;
			}
		}
		else {
			cout << "����㲻����Բ�����ϣ�" << endl;
		}
	}
	else {
		cout << "���벻�ܹ�����Բ���ߣ�" << endl;
	}
	system("pause");
}