#include <iostream>
using namespace std;
int main ()
{
	int f[36],n;
	f[1]=3;
	f[2]=8;
	for(int k=3;k<=35;k++)
	{
		f[k]=3*f[k-1]+f[k-2]-1;
	}
	f[1]=2;
	while (~scanf("%d",&n))
	{
		printf("%d\n",f[n]);
	}
	return 0;
}
