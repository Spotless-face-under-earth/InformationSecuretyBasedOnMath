#include<iostream>
#include<deque>
#include <math.h>
using namespace std;
void GetPrime(int numberToPrime,deque<int> &a)//
{
	int first = 2;
	while (first <= numberToPrime)
	{
		bool isPrime = true;
		for(int i=2;i<sqrt(first);i++)
		{
			if (first % i == 0)
			{
				isPrime = false;break;
			}
		}
		if (isPrime)
		{
			a.push_back(first);
		}
		first++;
	}
}
void FTOA(int number, deque<int>& a)
{
	cout << number<<"=";
	while (number != 1&&a.size()!=0)
	{
		int count = 0;
		while (number % a.front()==0)
		{
			number = number / a.front();
			count++;
		}
		if (count)
		{
			if (number != 1)
			{
				cout << a.front() << "^" << count << "*";
			}
			else
			{
				cout << a.front() << "^" << count;
			}
		}
		a.pop_front();
	}
}
