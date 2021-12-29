#include<bits/stdc++.h>
using namespace std;
#define MOD 1000007
typedef pair<int, int> pir;
struct Point
{
	int x, y, val;
	int fromx, fromy;
	Point(int _x, int _y, int _val) : x(_x), y(_y), val(_val)
	{ }
	bool operator < (Point t) const{
		return val > t.val;
	}
};

struct cmp1
{
	bool operator() (const Point *a,const Point *b) const
	{
		return a->val > b->val;
	}
};

int main()
{
	int m,n,x1,y1,x2,y2;
	cin>>m>>n;
	vector <vector<int>> graph(m, vector<int>(n));
	cin>>x1>>y1>>x2>>y2;
	for(int i=0;i<m;i++)
    {
		for(int j=0;j<n;j++)
			cin >> graph[i][j];
	}
	vector<vector<pir>> prev(m, vector<pir>(n));
	vector<vector<bool>> book(m, vector<bool>(n, false));
	vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
	priority_queue<Point*, vector<Point*>, cmp1> pq;
	Point* p = new Point(x1, y1, graph[x1][y1]);

	pq.push(p);
	dis[x1][y1] = 0;

	while(!pq.empty())
    {
		Point* now = pq.top();
		pq.pop();
		int x, y;
		x = now->x, y = now->y;

		if(book[x][y])
            continue;
		book[x][y]=true;

		if(graph[x+1][y] != -1 && !book[x+1][y])
        {
			if(dis[now->x][now->y] + graph[x+1][y] < dis[x+1][y])
			{
				dis[x+1][y] = dis[now->x][now->y] + graph[x+1][y];
				Point* p = new Point(x+1, y, dis[x+1][y]);
				pq.push(p);
				prev[x+1][y] = pir(x, y);
			}
		}
		if(graph[x-1][y] != -1 && !book[x-1][y])
		{
			if(dis[now->x][now->y] + graph[x-1][y] < dis[x-1][y])
			{
				dis[x-1][y] = dis[now->x][now->y] + graph[x-1][y];
				Point* p = new Point(x-1, y, dis[x-1][y]);
				pq.push(p);
				prev[x-1][y] = pir(x, y);
			}
		}
		if(graph[x][y+1] != -1 && !book[x][y+1])
		{
			if(dis[now->x][now->y] + graph[x][y+1] < dis[x][y+1])
			{
				dis[x][y+1] = dis[now->x][now->y] + graph[x][y+1];
				Point* p = new Point(x, y+1, dis[x][y+1]);
				pq.push(p);
				prev[x][y+1] = pir(x, y);
			}
		}
		if(graph[x][y-1] != -1 && !book[x][y-1])
		{
			if(dis[now->x][now->y] + graph[x][y-1] < dis[x][y-1])
			{
				dis[x][y-1] = dis[now->x][now->y] + graph[x][y-1];
				Point* p = new Point(x, y-1, dis[x][y-1]);
				pq.push(p);
				prev[x][y-1] = pir(x, y);
			}
		}
	}
	int P, Q;
	cout<<"("<<x2<<" "<<y2<<")";
	while(1)
    {
		P=x2,Q=y2;
		x2=prev[P][Q].first;
		y2=prev[P][Q].second;
		cout<<"("<<x2<<" "<<y2<< ")";
		if(x2==x1&&y2==y1)
            break;
	}

    return 0;
}

