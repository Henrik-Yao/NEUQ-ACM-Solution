#include<bits/stdc++.h>
using namespace std;

#define MAXL 100005
typedef pair<int, int> pir;
vector<bool> book;

void dijkstra(int source,int n,vector<vector<int>> graph,int des);

int main()
{
	int n,m;
	while(cin>>n>>m)
    {
		book = vector<bool>(n, false);
		vector<vector<int>> graph(n, vector<int>(n, 0));
		for(int i=0;i<n;i++)
		{
			int from,len,to;
			cin>>from>>len;
			for(int j=0;j<len;j++)
			{
				cin>>to;
				graph[from][to]=1;
			}
		}
		int source,destination;
		for(int k=0;k<m;k++)
		{
			cin>>source>>destination;
			dijkstra(source,n,graph,destination);
		}
	}
	return 0;
}


void dijkstra(int source,int n,vector<vector<int>> graph,int des)
{
	vector<bool> book(n,false);
	vector<int> dis(n,INT_MAX);
	priority_queue<pir,vector<pir>,greater<pir>> pq;
	pq.push(pir(0,source));
	dis[source]=0;
	while( !pq.empty() )
    {
		int now = pq.top().second;
		pq.pop();
		if(book[now])
            continue;
		book[now]=true;

		for(int i=0;i<n;i++)
        {
			if(graph[now][i]&&!book[i])
			{
				if(dis[i]>dis[now]+graph[now][i])
				{
					dis[i]=dis[now]+graph[now][i];
					pq.push(pir(dis[i],i));
				}
			}
		}
	}
	if(dis[des]!=INT_MAX)
	cout<<dis[des]<<endl;
	else
        cout<<"connection impossible"<<endl;

}
