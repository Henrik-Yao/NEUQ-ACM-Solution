#include <bits/stdc++.h>
using namespace std;
int a,b;
void sushu(int a,int b)
{
	int w[10005],x=0;
	for(int i=a;i<=b;i++)
	{
		int flag=0;
		if(i%2==0) continue;
		for(int j=3;j<=i/2;j=j+2)
		{
			if(i%j==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			w[++x]=i;
		}
	}
	for(int i=1;i<x;i++) cout<<w[i]<<" ";
	cout<<w[x]<<endl;
}
int main()
{
	while(cin>>a>>b) sushu(a,b);
	return 0;
}
