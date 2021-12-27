#include<bits/stdc++.h>
using namespace std;
int n,m,d,u,num,cnt;
struct Node
{
	int innum;
	int outnum;
	int to[105];
};
int main()
{
	while(cin>>n>>m)
	{
		num=0;
		cnt=0;
		Node node[105];
		for(int i=1;i<105;i++)
		{
			node[i].innum=0;
			node[i].outnum=0;
			for(int j=1;j<105;j++)
			node[i].to[j]=0;
		}
		queue<Node*>q;
		for(int i=1;i<=m;i++)
		{
			cin>>d>>u;
			node[d].outnum++;
			node[u].innum++;
			node[d].to[node[d].outnum]=u;
		}
		
		for(int i=1;i<=n;i++)
		if(node[i].innum==0)
		num++;
		int t;
		
		for(t=1;t<=n;t++)
		if(node[t].innum==0)
		{
			if(t==n+1)
			{
				cout<<"0"<<endl;
				continue;
			}
			else
			{
				q.push(&node[t]);
			}
		}
		while(!q.empty())
		{
			cnt++;
			Node* temp=q.front();
			q.pop();
			for(int j=1;j<=temp->outnum;j++)
			{
				node[temp->to[j]].innum--;
				if(node[temp->to[j]].innum==0)
				q.push(&node[temp->to[j]]);
			}
			
		}
		if(cnt>=n&&num>=2)
		cout<<"2"<<endl;
		else if(cnt>=n&&num==1)
		cout<<"1"<<endl;
		else
		cout<<"0"<<endl;	
	}
}
