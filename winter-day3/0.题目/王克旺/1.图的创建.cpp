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
	int n,e;
	cin>>n>>e;
	Node node[20000];
    int count[20000];
	for(int i=0;i<e;i++)
	{
		cin>>node[i].from>>node[i].to>>node[i].weight;
		count[node[i].from]++;
	}
	sort(node,node+e,Compair);
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(count[i]==0)
		{
			continue;
		}
		cout<<node[cnt].from<<":";
		for (int j=0;j<count[i];j++)
		{ 
			cout<<"("<<node[cnt].from<<","<<node[cnt].to<<","<<node[cnt].weight<<")";
			cnt++;
		}
		cout<<endl;
	}
	return 0;
}
