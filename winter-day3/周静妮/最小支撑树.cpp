#include <bits/stdc++.h>
using namespace std;
typedef struct
{
	int u,v,w;
}Edge;

int f[201];

bool cmp(Edge e1,Edge e2)
{
	return e1.w<e2.w;
}

int find(int x)
{
	if(x==f[x]) return x;
	else return find(x);
 } 
 
 int merge(int x,int y)
 {
 	int a=find(x);
 	int b=find(y);
 	if(a!=b)	
 	{
 		f[b]=a;
 		return 1;
	 }
	 return 0;
 }
int main()
{
	int n,e,i,cnt=1,sum=0;
	while(cin>>n>>e)
	{
		Edge edge[e];
		for(i=0;i<=200;i++)	f[i]=i;
		for(i=0;i<e;i++)	cin>>edge[i].u>>edge[i].v>>edge[i].w;
		sort(edge,edge+e,cmp);
		for(i=0;i<e;i++)
		{
			if(merge(edge[i].u,edge[i].v))
			{
				cnt++;
				sum+=edge[i].w;
			}
			if(cnt==n)	break;
		}
		if(cnt==n)	cout<<sum<<endl;
		else  cout << "There is no minimum spanning tree." << endl;
	}
	return 0;
}
