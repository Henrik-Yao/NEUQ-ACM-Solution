#include<iostream>
#include<vector>
using namespace std;

struct Node
{
	int v,l;
};

int n,e,start,stop;
vector <Node> v[1005];

int dist[1005];
int path[1005];
int visit[1005];

void Dijkstra(int start)
{
	fill(dist,dist+1005,10005);
	dist[start]=0;
	for(int i=0;i<n;i++)
        {
		int u=-1,mini =10005;
		for(int j=0;j<n;j++)
		{
			if(visit[j]==0&&dist[j]<mini)
			{
				mini=dist[j];
				u=j;
			}
		}
		if(u == -1)
            break;
		visit[u]=1;
		for (int j=0;j<v[u].size();j++)
		{
            int x = v[u][j].v;
            if (visit[x]==0&&dist[u]+v[u][j].l<dist[x])
            {
                dist[x]=dist[u]+v[u][j].l;
                path[x]=u;
            }
        }
	}
}

int main()
{
	cin>>n>>e;
    for (int i=0;i<e/2;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        v[a].push_back(Node{b, c});
        v[b].push_back(Node{a, c});
    }
    cin>>start>>stop;
    if (start == stop)
    {
        printf("%d-->%d:0",start,start);
        return 0;
    }
    Dijkstra(start);
    vector <int> ve;
    int x = stop;
    while (x!=start)
    {
        ve.push_back(x);
        x=path[x];
    }
    cout<<start;
    for (int i=ve.size()-1;i>=0;i--)
        cout<<"-->"<<ve[i];
    cout<<":"<<dist[stop];
}


