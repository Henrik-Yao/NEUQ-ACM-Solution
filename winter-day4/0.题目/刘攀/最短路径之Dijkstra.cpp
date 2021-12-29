#include<iostream>
#include<vector>
using namespace std;
#define INF 10001
struct Node{
	int v,l;//一条路的尾结点，该路的长度 
};
int n,e,from,to;
vector<Node> v[1001];
int dis[1001];
int path[1001];
int visit[1001];

void Dijkstra(int from){
	fill(dis,dis + 1001,INF);
	dis[from] = 0;
	for(int i = 0;i < n;i ++){
		int u = -1,minx = INF;
		for(int j = 0;j < n;j ++){
			if(visit[j] == 0 && dis[j] < minx){
				minx = dis[j];
				u = j;
			}
		}
		if(u == -1) break;	
		visit[u] = 1;
		for (int j = 0; j < v[u].size(); j++) {
            int x = v[u][j].v;
            if (visit[x] == 0 && dis[u] + v[u][j].l < dis[x]) {
                dis[x] = dis[u] + v[u][j].l;
                path[x] = u;
            }
        }
	}
}

int main(){
	cin >> n >> e;
    for (int i = 0; i < e / 2; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(Node{b, c});
        v[b].push_back(Node{a, c});
    }
    cin >> from >> to;
    if (from == to) { 
        printf("%d-->%d:0",from,from);
        return 0;
    }
    Dijkstra(from);
    vector<int> ve;
    int x = to;
    while (x != from) {
        ve.push_back(x);
        x = path[x];
    }
    cout << from;
    for (int i = ve.size() - 1; i >= 0; i--)
        cout << "-->" << ve[i];
    cout << ":" << dis[to];
}



