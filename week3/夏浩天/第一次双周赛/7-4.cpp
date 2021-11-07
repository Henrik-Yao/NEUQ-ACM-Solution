#include <iostream>
#include<cmath>
#include<string.h>
using namespace std;
unsigned long long a[66];
unsigned long long b[66];
int main()
{
	int n;while( cin >> n){
	
		memset(b, 92233720368, sizeof(b));
		a[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			a[i] = 2 * a[i - 1] + 1;
		}
		b[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j < i; j++)
			{
				long long c = a[i - j] + b[j] * 2;
				if (c < b[i])
					b[i] = c;
			}
		}
		cout<<b[n]<<endl;
}
}