#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10001][10001];//a[x][y]=p表示x城的第y条路通向p城 
int num[10001],num2[10001];
void clear(int k)
{
	if(num2[k]!=0)
	{
		num2[k]=0;
		for(int i=1;i<=num[k];i++)
		num2[a[k][i]]--;
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int b,c;
		cin>>b>>c;
		num[b]++;num[c]++;
		a[b][num[b]]=c;a[c][num[c]]=b;//搭路 
	}
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		num2[j]=num[j];
		int np,v;
		cin>>np;
		for(int j=1;j<=np;j++)
		{
			cin>>v;
			clear(v);//清路 
		}
		int judge=0;
		for(int j=1;j<=n;j++)
		if(num2[j]>0)
		{
			judge=1;
			cout<<"NO"<<endl;
			break;
		}
		if(judge==0)
		cout<<"YES"<<endl;
	}
}
