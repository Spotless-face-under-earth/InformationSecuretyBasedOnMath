#include "source.h"
#include "SquareReverse.h"
#include"Reverse.h"
#include"math.h"
#include <iostream>
using namespace std;
/// <summary>
///信息安全数学基础课程椭圆曲线相关计算问题
/// 作者：jch
/// 日期：2024.5.23
/// </summary>
/// <param name="a"></param>
/// <param name="m"></param>
/// <returns></returns>
int rever(int a, int m) {
	//这里也是一个坑，需要考虑负数的情况
	while (a < 0)a += m;
	int uro = getEuroFunc(m)-1;
	int biouro[100];
	int bionum = toBio(biouro, uro);
	int ans = squareMod(biouro, a, m, bionum);
	while (ans < 0)ans += m;
	return ans;
}
//得到一个非整数的数的模
int ModAns(double a, int m)
{
	int devideNum = 1;int devided = 1;//分别为除数和被除数
	if (a - int(a))
	{
		double tempa = a;
		for (;;devided++)
		{
			if (tempa * devided - int(tempa * devided)) {
				if (devided > 23)return -1;
			}
			else {
				devideNum = a * devided;break;
			}
		}
		int bioEuro[100];
		//int bioEuro_2[100];
		int Eruo_1Num = toBio(bioEuro, devided - 1);
		int mod1 = squareMod(bioEuro, devided, m, Eruo_1Num);
		//int Euro_2Num = toBio(bioEuro_2,mod1*devideNum);
		int mod2 = (devideNum * mod1) % m;
		return mod2;
	}
	else 
	{
		//int bioDex[100];
		//int bioEuro_2[100];
		//int Eruo_1Num = toBio(bioDex,a);
		int mod1 =int(a) % m;
		return mod1;
	}
}

//得到所有素因子
// deque<int> getPrimeFactor(int n)
// {
// 	deque<int> PrimeNums;
// 	PrimeNums.push_back(2);PrimeNums.push_back(3);
// 	for (int i = 5;i <= n;i++)
// 	{
// 		bool isPri = true;
// 		for (int j = 2;j <= sqrt(i);j++)
// 		{
// 			if (i % j == 0) { isPri = false;break; }
// 		}
// 		if (isPri)PrimeNums.push_back(i);
// 	}
// 	return PrimeNums;
// }

//得到与该数非互素的素数
// deque<int> getNotFactorPrime(int n)
// {
// 	deque<int> notFactor;
// 	deque<int> isPrime = getPrimeFactor(n);
// 	while (!isPrime.empty())
// 	{
// 		if (n % isPrime.front() == 0) { notFactor.push_back(isPrime.front());isPrime.pop_front(); }
// 		else isPrime.pop_front();
// 	}
// 	return notFactor;
// }

//得到欧拉函数
// int getEuroFunc(int a)
// {
// 	if (getPrimeFactor(a).size() == a - 2)return a - 1;
// 	else
// 	{
// 		int EuroFunc = a;
// 		deque<int> tempNot = getNotFactorPrime(a);
// 		while (!tempNot.empty())
// 		{
// 			EuroFunc = (EuroFunc * (tempNot.front() - 1) / tempNot.front());
// 			tempNot.pop_front();
// 		}
// 		return EuroFunc;
// 	}
// 	;
// }
bool EllipticCurve::isOnCurve(Node p)
{
	int third[2]{ 1,1 };
	int twice[2]{ 1,0 };
	if (((squareMod(third, p.xp, this->p, 1) + this->a * p.xp + this->b) % this->p) == p.yp*p.yp %this->p)
		return true;
	return false;

}

Node EllipticCurve::addP(Node a, Node b )
{
	int k=0;
	Node ans(0, 0);
	if (a.xp == b.xp && a.yp==b.yp) 
	{
		//这里是个巨坑，因为存在约分的问题，所以不能直接用小数
		//切记切记！！！
		int tempUp = (3* a.xp * a.xp + this->a)%p;
		int tempDown=(2 * a.yp);
		k = (rever(tempDown,p)*tempUp)%p;
		//cout << "k同余" << k<<endl;
	}
	else
	{
		int tempUp = ((a.yp) - b.yp) % p;
		int tempDown = (a.xp - b.xp);
		k = (tempUp * rever(tempDown,p)) % p;
	/*	double temp = (static_cast<double>(a.yp) - b.yp) / (a.xp - b.xp);
		k = ModAns(temp, p);*/
		//cout << "k同余" << k << endl;
	}
	ans.xp = (k * k - a.xp - b.xp) % p;
	while (ans.xp < 0)ans.xp += p;
	ans.yp =( k * (a.xp - ans.xp) - a.yp)%p;
	while (ans.yp < 0)ans.yp += p;
	return ans;
}

Node EllipticCurve::multiAddP(int n, Node p)
{
	int bioN[100];
	int NNum = toBio(bioN, n);//返回即最高位位数数组
	Node initP(p.xp, p.yp);
	Node tempP(p.xp, p.yp);
	for (int i = NNum-1;i>=0;i--)
	{
		//当当前P为无穷远点时，结果为P
		if (tempP.xp == -1 && tempP.yp == -1)
		{
			tempP = initP;
		}
		else {

			if (bioN[i] == 0)tempP = this->addP(tempP, tempP);
			else tempP = this->addP(this->addP(tempP, tempP), initP);
			//计算结果得到无穷远点时，横纵坐标均为-1；
			if (tempP.xp == initP.xp)
			{
				tempP = Node(-1, -1);
				i--;
			}
		}
	}	
	return tempP;
}

int EllipticCurve::getOrdP(Node p)
{
	int OrdP = 1;
	Node initP(p.xp, p.yp);
	p = this->addP(p, initP);
	while ((p.xp!=initP.xp)) {
		p = this->addP(p, initP);
		OrdP++;
		if (OrdP == 100) {
			cout << "GET ORDER ERROR" << endl;
			return -1;
		}
	}
	return OrdP+2;
}

int EllipticCurve::getPNum()
{
	int ans = 0;
	for (int i = 0;i < this->p;i++)
	{
		int y2 = EllipticCurveAlu(i);
		if (y2 != -1)
		{
			double temp = sqrt(y2);
			while (temp - int(temp))
			{
				y2 += this->p;
				temp = sqrt(y2);
			}
			if (y2)
			{
				ans += 2;
			}
			else ans++;
		}
	}
	return ans+1;
}


deque<Node> EllipticCurve::getP()
{
	deque<Node> ans;
	for (int i = 0;i < this->p;i++)
	{
		int y2 = EllipticCurveAlu(i);
		if ( y2!= -1)
		{
			double temp = sqrt(y2);
			while (temp - int(temp))
			{
				y2 += this->p;
				temp = sqrt(y2);
			}
			if (y2)
			{
				ans.push_back(Node(i, int(temp)));ans.push_back(Node(i, p - int(temp)));
			}
			else ans.push_back(Node(i, int(temp)));
		}
		//这里严格来说需要判断是否有二次剩余，我默认输入模数都为素数，所以偷懒了
	}
	return ans;
}
//计算椭圆曲线的函数值
int EllipticCurve::EllipticCurveAlu(int x)
{
	int y2 = (x * x * x + x * this->a + this->b)%this->p;
	//这里应该判断一下是否是二次剩余，但是由于勒让比或雅可比等于-1时一定无解，所以直接输出-1
		int temindex = (p - 1) / 2;
		int tempbio[100];int tempnum = toBio(tempbio, temindex);
		int judgeInt = squareMod(tempbio, y2, this->p, tempnum);
		if (judgeInt == 1)
		{
			return y2;
		}
		else {
			return -1;
		}
	
}

bool isEllipticCurve(int a, int b, int p)
{
	int bioa[100], biob[100];
	int anum = toBio(bioa, a);
	int third[2]{ 1,1 };
	int twice[2]{ 1,0 };
	int bnum = toBio(biob, b);
	int tempa = squareMod(third, a, p, 2);
	int tempb = squareMod(twice, b, p, 2);
	if ((4*tempa + 27*tempb) % p != 0) 
	{
		return true;
	}
	return false;
}
