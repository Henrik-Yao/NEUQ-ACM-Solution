#include<iostream>
using namespace std;
int fent(int x);
int main()
{
	int n,c=0;
	scanf("%d",&n);
	c=fent(n);
	printf("%d",c+1);
	return 0;
} 
int fent(int x)
{
	int cnt=0;
	for(int i=1;i<x;i++)
	{
		if(x%i==0)
		{
			cnt++;
			cnt+=fent(i);
		}
	}
	return cnt;
}
