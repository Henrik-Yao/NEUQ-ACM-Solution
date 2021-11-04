#include <bits/stdc++.h>
using namespace std;
int visit[100000]={1,1};//0£¬1²»ÊÇËØÊı
int shu[10000]; 
int main()
{
	int a,b;
	for(int i=2;i<=10000;i++)
	{
		if(!visit[i])
		{
			for(int k=i*i;k<=10000;k+=i)
			{
				visit[k]=1;
			}
		}
	}
	
	while(cin>>a>>b)
	{
		int con=0;
		for(int i=a;i<=b;i++)
		if(!visit[i])
		shu[++con]=i;
		
		for(int j=1;j<con;j++)
		cout<<shu[j]<<" ";
		cout<<shu[con]<<endl;
    }
	return 0;
}
