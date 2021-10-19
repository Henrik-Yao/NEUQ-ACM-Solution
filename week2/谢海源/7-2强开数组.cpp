#include<bits/stdc++.h>
using namespace std;
int s1[10005]={};
int s2[10005]={};
int t[10005][10005]={};
int main()
{
	int n,m,k,a,b;
	cin>>n>>m;
	for(int i=1;i<=m;i++)//记录连接情况
	{
		cin>>a>>b;
		s1[a]++;
		s1[b]++;
		t[a][s1[a]]=b;
		t[b][s1[b]]=a;
	}
    cin>>k;
    while(k--)
    {
    	for(int i=1;i<=n;i++)//初始化状态
    	{
			s2[i]=s1[i];			
		}
    	int x,v,f=1;
    	cin>>x;
    	while(x--)//某组方案
    	{
			cin>>v;//炸v城
			for(int i=1;i<=s1[v];i++)
			{
				s2[t[v][i]]--;
			}
			s2[v]=0;
		}
		for(int i=1;i<=n;i++)//检验
		{
			if(s2[i]>0)
			{
				f=0;
				printf("NO\n");
				break;
			}
		}
		if(f==1) printf("YES\n");
	}
    return 0;
}