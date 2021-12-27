#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int from;
	int to;
	int weight;
};
bool Compair(Node a, Node b)
{
	if(a.from!=b.from)
	{
		return a.from<b.from;
	}
	else
	{
		return a.to<b.to;
	}	
}
int main()
{
	int n,e,k;
	cin>>n>>e;
	Node node[20000];
    int count[20000]={0},counts[20000]={0};
	for(int i=0;i<e;i++)
	{
		cin>>node[i].from>>node[i].to>>node[i].weight;
		count[node[i].from]++;
		counts[node[i].from]++;
	}
	sort(node,node+e,Compair);
	int a[1000],b[1000];
	cin>>k;
	for(int i=0;i<k;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<e;i++)
	{
		for(int j=0;j<k;j++)
		{
			if(node[i].from==a[j]&&node[i].to==b[j])
			{
				counts[node[i].from]--;
			}
		}
    }
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(counts[i]==0)
		{
			cnt+=count[i]-counts[i];
			continue;
		}
		cout<<node[cnt].from<<":";
		for(int j=0;j<count[i];j++)
		{ 
			int flag=1;
			for(int t=0;t<k;t++)
			{
				if(node[cnt].from==a[t]&&node[cnt].to==b[t])
				{
					flag=0;
				}
			}
			if(flag==1)
			{
				cout<<"("<<node[cnt].from<<","<<node[cnt].to<<","<<node[cnt].weight<<")";
			}
			cnt++;
		}
		cout<<endl;
	}
	return 0;
}
