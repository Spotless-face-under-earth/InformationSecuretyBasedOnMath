#include<iostream>
#include<math.h>
#include<cmath>
#include <deque>
using namespace std;
bool IsPrime(int numberToPrime,int &total) 
{
	int first = 2;
	while (first <= sqrt(numberToPrime)) 
	{
		if (numberToPrime % first == 0)return false;
		first++;
	}
	return true;
}
void Eratos(int numberToEra,int &total)
{
	deque<int>primeNumber;
	int first = 2;
	while (first <= sqrt(numberToEra))
	{
		if (IsPrime(first,total)) 
		{
			cout << first << " ";primeNumber.push_back(first);total++;
		}
		first++;
	}
	int last = int(sqrt(numberToEra)+1);
	for (;last <= numberToEra;last++)
	{ 
		bool IsPrime = true;
		for (int countt = 0;countt < primeNumber.size();countt++) 
		{
			if (last % primeNumber.at(countt) == 0)
			{
				IsPrime = false;
				break;
			}
		}
		if (IsPrime)
		{
			cout << last << " ";total++;
		}
	}
}
