#include<bits/stdc++.h>
using namespace std;

int tag[505] = {0};
vector<int> edge[505];
bool res = true;//�Ƿ���Ǣ 

int dfs(int from, int to){//���ص� to ��·������ 
	int now = 0;
	if(tag[from]) return tag[from];
	if(from == to) return 1;
	for(auto it : edge[from]){
		now += dfs(it, to);
	}
	tag[from] = now;
	if(!now) res = false;
	return now;
}

int main() {
	int n, m; //���������������� 
	cin >> n >> m;//n���ڵ㣬m���� 
	for(int i=1;i<=m;++i)
	{
		int u,v;
		cin>>u>>v;
		edge[u].push_back(v);
	}
	int from, to;
	cin >> from >> to;
	int k = dfs(from, to);
	
	cout << k;
	if(res) cout << " Yes" << endl;
	else cout << " No" << endl;
}
