#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	double a[65];
	double b[65];
	a[1] = 1;
	for(int i=2;i<=64;i++)
	{
		a[i] = 2 * a[i-1] + 1,b[i] = 1.84467e+0300;
	}
	b[1] = 1;
	for(int i=2;i<=64;i++)
	{
		for(int j=1;j<i;j++)
		{
			b[i] = min(b[i],b[j]*2+a[i-j]);
		}
	}
	while(cin>>n)
	{
		cout<<b[n]<<"\n";
	}
	
	return 0;
}

//递归，多一根柱子的区别在于可以将第二次出柱的盘子置于d。