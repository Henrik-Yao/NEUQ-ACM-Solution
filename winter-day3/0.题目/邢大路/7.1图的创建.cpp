#include<bits/stdc++.h>
using namespace std;
struct Node{
	int from;
	int to;
	int w;
}node[20005];
bool cmp(Node a,Node b)
{
	if(a.from!=b.from)  return a.from<b.from;
	return a.to<b.to;
}
int num[20005];
int main()
{
	int n,m;
	cin>>n>>m;
	for (int i=0;i<m;i++)
	{
	cin>>node[i].from>>node[i].to>>node[i].w;
	num[node[i].from]++;
	}
	sort(node,node+m,cmp);
	// ¥Ú”°
	int count=0;
	for(int i=0;i<n;i++)
	{
	if(num[i] == 0) continue;
	int sum=num[i];
	printf("%d:",node[count].from);
	for (int j=0;j<sum;j++)
		{ 
		printf("(%d,%d,%d)", node[count].from, node[count].to, node[count].w);
		count++;
		}
	cout<<endl;
	}
	return 0;
}

