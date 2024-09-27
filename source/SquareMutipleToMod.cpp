#include<iostream>
#include<math.h>

using namespace std;

int toBio(int a[],int x)
{
	int num = 0;
	while(x != 0) 
		{
			a[num] = x % 2;//二进制顺序与表达顺序相反
			x = x / 2;
			//cout << a[num]<<"*";
			num++;
		}
	return num-1;
}
int squareMod(int a[],int b,int m,int num)
{
	long int ans = 1;
	
	while (num >= 0)
	{
		if (a[num] == 1)
		{
			ans = (ans * ans) % m;
			ans = (ans * b) % m;
			if (ans < 0) {
				ans += m;
			}
		}
		else
		{
			ans = (ans * ans) % m;
			if (ans < 0) {
				ans += m;
			}
		}
		num--;
	}
	return ans;
	//cout<<" Answer:" << ans << endl;
}


