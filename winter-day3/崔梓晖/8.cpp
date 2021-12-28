#include <bits/stdc++.h>
using namespace std;
int n,m,a[500][500],in[1000];
int main()
{
	while(cin>>n>>m)
	{
		int u,v,tot=0,pd[1001],sp=0,qq=0;
		queue<int>q;
		memset(in,0,sizeof(0));
		memset(pd,0,sizeof(pd));
        memset(a,0,sizeof(a));
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v;
			a[u][v]=1;
			in[v]++;
		} 
		for(int i=1;i<=n;i++)
		{
			if(in[i]==0)
			{
				q.push(i);
				tot++;
				pd[i]=1;
				qq++;
			}
		}
		if(qq>1)
		{
			sp=1;
		}
		while(q.size()!=0)
		{
			int cnt=0;
			int x=q.front();
			//cout<<x<<endl;
			q.pop();
			for(int i=1;i<=n;i++)
			{
				if(a[x][i]==1&&pd[i]==0)
				{
					a[x][i]=0;
					in[i]--;
				}
				if(in[i]==0&&pd[i]==0)
				{
					//cout<<"i"<<i<<endl;
					q.push(i);
					pd[i]=1;
					tot++;
					cnt++;
					//cout<<"cnt"<<cnt<<endl;
				}
			}
			if(cnt>1)
			{
				sp=1;
			}
		}
		//cout<<"tot"<<tot<<endl;
		if(tot!=n)
		{
			cout<<"-1"<<endl;
		}
		else 
		{
			if(sp==1)
			{
				cout<<"2"<<endl;
			}
			else if(sp==0)
			{
				cout<<"1"<<endl;
			}
			
		}
	}
	return 0;
}
