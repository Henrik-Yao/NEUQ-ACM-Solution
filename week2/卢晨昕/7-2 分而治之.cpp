#include<bits/stdc++.h>
using namespace std;
int n,m,k,np;
int num[10005];
struct node
{
	int fr,to,nex;
}e[20005];
int cnt=0;
int head[20005];
void add(int a,int b)
{
	e[++cnt].fr=a;
	e[cnt].to=b;
	e[cnt].nex=head[a];
	head[a]=cnt;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
    	int a,b;
    	cin>>a>>b;
    	add(a,b);
    	add(b,a);
    	num[a]++;
    	num[b]++;
	}
	cin>>k;
	while(k--)
	{
		int numm[100005];
		for(int i=1;i<=n;i++)
		{
			numm[i]=num[i];
		}
		cin>>np;
		for(int i=1;i<=np;i++)
		{
			int g;
			cin>>g;
			numm[g]=0;
			for(int j=head[g];j;j=e[j].nex)
			{
				int y=e[j].to;
				numm[y]--;
			}
		}
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			if(numm[i]>0)
			{
				cout<<"NO"<<endl;
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}
