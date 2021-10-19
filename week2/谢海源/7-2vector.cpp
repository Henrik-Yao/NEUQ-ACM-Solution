#include<bits/stdc++.h>
using namespace std;
int s1[10001]={};
int s2[10001]={};
vector<int>t[100001];//二维数组(伪)开冲 
int main()
{
    int n,m,k,a,b;
	cin>>n>>m;
	for(int i=1;i<=m;i++)//记录连接情况
	{
		cin>>a>>b;
		t[a].push_back(b);
		s1[a]++;
		t[b].push_back(a);
		s1[b]++;
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
			s2[v]=0;
			int i;
			for(auto i:t[v])//遍历	    
			{
			    s2[i]--;
			}		
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