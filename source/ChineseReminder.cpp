#include<iostream>
#include <Reverse.h>
using namespace std;
// int ReverseEuclid(int source1, int source2)
// {
// 	bool sr1mores2 = false;
// 	long int t[100], s[100], q[100];
// 	int a = source1;
// 	int b = source2;
// 	s[0] = 1;s[1] = 0;
// 	t[0] = 0;t[1] = 1;
// 	int count = 1;
// 	if (source1 > source2)
// 	{
// 		sr1mores2 = true;
// 		q[1] = a / b;
// 		source1 = source1 % source2;
// 	}
// 	else {
// 		source2 = source2 % source1;
// 		q[1] = b / a;
// 	}
// 	//int addCount = 0;
// 	while (source1 != 0 && source2 != 0)
// 	{
// 		//addCount++;
// 		//count++;
// 		while (source1 > source2 && source2 != 0)
// 		{
// 			count++;
// 			q[count] = source1 / source2;
// 			s[count] = s[count - 2] - q[count - 1] * s[count - 1];
// 			t[count] = t[count - 2] - q[count - 1] * t[count - 1];
// 			source1 = source1 % source2;
// 		}
// 		while (source1 <= source2 && source1 != 0)
// 		{
// 			count++;
// 			q[count] = source2 / source1;
// 			s[count] = s[count - 2] - q[count - 1] * s[count - 1];
// 			t[count] = t[count - 2] - q[count - 1] * t[count - 1];
// 			source2 = source2 % source1;
// 		}
// 	}
// 	if (s[count] < 0 || t[count] < 0)		//保证得到的余数为正数
// 	{
// 		if (s[count] < 0)s[count] += b;
// 		else t[count] += a;
// 	}
// 	return s[count];
// }
void ChineseResidueTheory() 
{
	//数据输入
	int n;
	cout << "n=";
	cin >> n;
	int* remainder = new int(n);
	for (int remainderIN = 0;remainderIN < n;remainderIN++)
	{
		cout << " b_" << remainderIN<<"=";
		cin >>*( remainder+remainderIN);
	}
	int* primeNum = new int(n);
	for (int primeIN = 0;primeIN < n;primeIN++)
	{
		cout << " m_" << primeIN << "=";
		cin >> *(primeNum + primeIN);
	}
	//算法开始,调用之前求逆欧几里得逆元方法
	int *M = new int(n);
	int* MReverse = new int(n);
	for (int i = 0;i < n;i++)
	{
		int tempNum = 1;
		for(int j=0;j<n;j++)
		{
			if (i != j) {
				tempNum *= *(primeNum + j);
			}
		}
		*(M + i) = tempNum;
		*(MReverse + i) = ReverseEuclid(tempNum, *(primeNum + i));
	}
	int answerToRe=0;int finalPri=1;
	for (int i = 0;i < n;i++)
	{
		answerToRe += (*(M + i)) * (*(MReverse + i))*(*(remainder+i));
		finalPri *= *(primeNum+ i);
	}
	answerToRe = answerToRe % finalPri;
	cout << "X同余" << answerToRe << " (mod " << finalPri << ")";
}
