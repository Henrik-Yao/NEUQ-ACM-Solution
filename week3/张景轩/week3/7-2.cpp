#include<iostream>
#include<vector>
using namespace std;

int tg[505] = {0};
vector<int> e[505];
bool res = true;

int dfs(int front, int rear){
	int now = 0;
	if(tg[front]) 
    {
        return tg[front];
    }
	if(front == rear) 
    {
        return 1;
    }
	for(auto it : e[front])
    {
		now += dfs(it, rear);
	}
	tg[front] = now;
	if(!now) res = false;
	return now;
}

int main() {
	int n, m;
	cin >> n >> m;
	for(int i=1;i<=m;++i)
	{
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
	}

	int front, rear;
	cin >> front >> rear;
	int k = dfs(front, rear);
	
	cout << k;
	if(res) cout << " Yes" << endl;
	else cout << " No" << endl;
}

//对结点a深度优先遍历，返回不同路径数量，中间需要保存结果