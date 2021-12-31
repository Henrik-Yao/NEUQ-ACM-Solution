#include<bits/stdc++.h>
using namespace std;

#define MAXL 20001
int n, m; //n���㣬m���� 
set<int> graph[MAXL]; // vector��ͼ 
bool book[MAXL] = {false}; // ��¼�Ƿ񱻱����� 

void dfs(int x) {//�Ե�x���� 
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
	for(int i = 0; i < m; i++){ //�ڵ��0��ʼ 
		cin >> from >> to;
		graph[from].insert(to);
	}
	for(int i = 0; i < n; i++){
		dfs(i);
	}
}
