#include<iostream>
#include<deque>
#include<math.h>
#include<iomanip>
#include <SquareReverse.h>
using namespace std;
//求与该数互素的数
deque<int> getPrimeFactor(int n)
{
	deque<int> allPossibleNum;
	int* p = new int[n];
	for (int i = 2;i < n;i++)
	{
		p[i] = i;
	}
	for (int i = 2;i < n;i++)
	{
		if (n % i == 0)
		{
			for (int k = 1;k <= n / i;k++)
			{
				p[i * k] = -1;
			}
		}
	}
	for (int i = 2;i < n;i++)
	{
		if (p[i] > 1)allPossibleNum.push_back(p[i]);
	}
	return allPossibleNum;
}

//找到小于n(n>=4)的数的所有素数
static deque<int> getPrimeNum(int n)
{
	deque<int> PrimeNums;
	PrimeNums.push_back(2);PrimeNums.push_back(3);
	for (int i = 5;i <=n;i++)
	{
		bool isPri = true;
		for (int j = 2;j <= sqrt(i);j++)
		{
			if (i % j == 0) { isPri = false;break; }
		}
		if (isPri)PrimeNums.push_back(i);
	}
	return PrimeNums;
}
//得到与该数非互素的素数
deque<int> getNotFactorPrime(int n)
{
	deque<int> notFactor;
	deque<int> isPrime = getPrimeNum(n);
	while (!isPrime.empty())
	{
		if (n % isPrime.front() == 0) { notFactor.push_back(isPrime.front());isPrime.pop_front(); }
		else isPrime.pop_front();
	}
	return notFactor;
}
//求欧拉函数的值
int getEuroFunc(int a)
{
	if (getPrimeFactor(a).size() == a - 2)return a - 1;
	else
	{
		int EuroFunc = a;
		deque<int> tempNot = getNotFactorPrime(a);
		while (!tempNot.empty())
		{
			EuroFunc= (EuroFunc*(tempNot.front()-1)/ tempNot.front());
			tempNot.pop_front();
		}
		return EuroFunc;
	}
	;
}
//将x转化为二进制数存在a[]中，便于进行平方模运算
// int toBio(int a[], int x)
// {
// 	int num = 0;
// 	while (x != 0)
// 	{
// 		a[num] = x % 2;
// 		x = x / 2;
// 		//cout << a[num]<<"*";
// 		num++;

// 	}
// 	//假设输入为0
// 	if (x == 0 && num == 0) { a[0] = 0;return 1; }
// 	return num - 1;
// }

//num为a[]中元素个数，计算pow(b,a)%m;
// static int squareMod(int a[], int b, int m, int num)
// {
// 	long int ans = 1;
// 	while (num >= 0)
// 	{
// 		if (a[num] == 1)
// 		{
// 			ans = (ans * ans) % m;
// 			ans = (ans * b) % m;
// 			if (ans < 0) {
// 				ans += m;
// 			}
// 		}
// 		else
// 		{
// 			ans = (ans * ans) % m;
// 			if (ans < 0) {
// 				ans += m;
// 			}
// 		}
// 		num--;
// 	}
// 	return ans;
// 	//cout << " Answer:" << ans << endl;
// }

//得到最小原根
static int getMinPrimodialRoot(int x)
{
	deque<int> tempt = getPrimeFactor(x);
	int tempEuro = getEuroFunc(x);
		while (!tempt.empty())
		{
			int temTry = tempt.front();
			int i = 2;
			int* a = new int[10000];
			for (i;i < tempEuro;i++)
			{
				int addNum = squareMod(a, temTry, x, toBio(a, i));
				if (addNum < 0)addNum += x;
				if (addNum == 1)
				{
					break;
				}
				//int addNum = int(pow(temTry, tempEuro)) % x;
				//pow()函数最大只能识别2e64，越界了；
			}
			delete[] a;
			if (i == tempEuro)return temTry;
			//else cout << addNum % x << endl;
			tempt.pop_front();
		}
		//cout << "System Error!Sorry for the bug!" << endl;
		if (x == 2)return 1;
		return -1;
}
//根据原数和最小原根得到指数表
int* getIndexTable(int n,int root)
{
	deque<int> tempIndex;
	for (int i = 0;i < getEuroFunc(n);i++)
	{
		tempIndex.push_back(i);
	}
	int* a = new int[5000];
	while(true)
	{
		int b[1000];
		int bNum = toBio(b, tempIndex.front());
		int k = squareMod(b, root, n, bNum);
		a[k] = tempIndex.front();
		tempIndex.pop_front();
		if (tempIndex.empty())break;
	}
	return a;
}
// int main()
// {
// 	int n;
// 	cout << "Please input n(n>0) :";
// 	cin >> n;
// 	int g = getMinPrimodialRoot(n);
// 	if (g != -1)
// 	{
// 		cout << "The min primitive root of " << n << ": g=" << g << endl;
// 		cout << "The ind_table of " << n << " based on " << g << " is:" << endl;

// 		int* IndexTablePoint = getIndexTable(n, g);
// 		cout << setw(5) << setiosflags(ios::left) << " " << " ";
// 		//输出行序号
// 		for (int i = 0;i <= 9;i++) {
// 			cout << setw(5) << setiosflags(ios::left) << i;
// 		}
// 		cout << endl << endl;
// 		//输出列序号以及每列
// 		for (int j = 0;j <= int((n - 1) / 10);j++)
// 		{
// 			cout << setw(5) << setiosflags(ios::left) << j << " ";
// 			int rowNum = 10;
// 			while (rowNum)
// 			{
// 				if (*(IndexTablePoint + j * 10 + 10 - rowNum) >= 0)cout << setw(5) << setiosflags(ios::left) << *(IndexTablePoint + j * 10 + 10 - rowNum);
// 				else cout << setw(5) << setiosflags(ios::left) << "-";
// 				rowNum--;
// 			}
// 			cout << endl;
// 		}
// 		delete[] IndexTablePoint;
// 	}
// 	else cout << "No Primodial Root!" << endl;
// }