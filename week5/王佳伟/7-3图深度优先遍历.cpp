#include<bits/stdc++.h>
using namespace std;

#define MAXL 20001
int n, m; //n个点，m条边 
set<int> graph[MAXL]; // vector存图 
bool book[MAXL] = {false}; // 记录是否被遍历过 

void dfs(int x) {//对点x深搜 
	if(book[x]) return;
	book[x] = true; 
	cout << x << " ";
	for(auto it : graph[x]){
		dfs(it);
	}
}

int main() {
	int from, to;
	cin >> n >> m;
	for(int i = 0; i < m; i++){ //节点从0开始 
		cin >> from >> to;
		graph[from].insert(to);
	}
	for(int i = 0; i < n; i++){
		dfs(i);
	}
}
