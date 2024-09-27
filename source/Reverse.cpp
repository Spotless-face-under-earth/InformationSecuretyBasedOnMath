#include<iostream>
#include<math.h>
using namespace std;

int ReverseEuclid(int source1, int source2)
{
	bool sr1mores2 = false;
	long int t[100], s[100], q[100];
	/*cout << "a=";
	cin >> source1;
	cout << "b=";
	cin >> source2;*/
	int a = source1;
	int b = source2;
	s[0] = 1;s[1] = 0;
	t[0] = 0;t[1] = 1;
	int count = 1;
	if (source1 > source2)
	{
		sr1mores2 = true;
		q[1] = a / b;
		source1 = source1 % source2;
	}
	else {
		source2 = source2 % source1;
		q[1] = b / a;
	}
	//int addCount = 0;
	while (source1 != 0 && source2 != 0)
	{
		//addCount++;
		//count++;
		while (source1 > source2 && source2 != 0)
		{
			count++;
			q[count] = source1 / source2;
			s[count] = s[count - 2] - q[count - 1] * s[count - 1];
			t[count] = t[count - 2] - q[count - 1] * t[count - 1];
			source1 = source1 % source2;
		}
		while (source1 <= source2 && source1 != 0)
		{
			count++;
			q[count] = source2 / source1;
			s[count] = s[count - 2] - q[count - 1] * s[count - 1];
			t[count] = t[count - 2] - q[count - 1] * t[count - 1];
			source2 = source2 % source1;
		}
	}
	if (s[count] < 0 || t[count] < 0)		//保证得到的余数为正数
	{
		if (s[count] < 0)s[count] += b;
		else t[count] += a;
	}

	/*
	if (max(source1, source2) != 1)
	{
		cout << "gcd(" << a << "," << b << ")=" << max(source1,source2) << endl;
		cout << "lcm(" << a << "," << b << ")=" << a * b / max(source1,source2) << endl;
		cout << "No inverse element fit to mod each!" << endl;
	}
	else {
		cout << "gcd(" << a << "," << b << ")=1" << endl;
		cout << "lcm(" << a << "," << b << ")=" << a * b << endl;
		if (sr1mores2)
		{
			if (s[count] < 0 || t[count] < 0)		//保证得到的余数为正数
			{
				if (s[count] < 0)s[count] += b;
				else t[count] += a;
			}
			cout << a << " 逆元：" << s[count] << "(mod " << b << ")" << endl << b << " 逆元：" << t[count] << "(mod " << a << ")" << endl;
		}
		else
		{
			if (s[count] < 0 || t[count] < 0)
			{
				if (s[count] < 0)s[count] += a;
				else t[count] += b;
			}
			cout << a << " 逆元：" << t[count] << "(mod " << b << ")" << endl << b << " 逆元：" << s[count] << "(mod " << a << ")"<<endl;
		}
	}
	int j = 0;
	while (j < 15)
	{
		cout << "*";j++;
	}
	cout << endl;
	*/
	//cout << s[count] << endl;
	return s[count];
}