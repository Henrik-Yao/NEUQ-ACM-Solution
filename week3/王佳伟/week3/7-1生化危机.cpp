#include<bits/stdc++.h>
using namespace std;

int safe[55] = {0};
bool book[101] = {false};//�Ƿ������ 
bool res = false;
vector<vector<int>> road;

void dfs(int s, int t);

int main() {
	int m, n, k; //���и�������ȫ���и�������·���� 
	cin >> m >> n >> k;
	road.resize(m);
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		safe[t] = 1;
	}
	for(int i = 0; i < k; i++){
		int from, to;
		cin >> from >> to;
		road[from].push_back(to);
		road[to].push_back(from);
	}
	int s, t;//���ڳ��У�Ŀ����� 
	cin >> s >> t;
	book[s] = true;
	dfs(s, t);
	
	
	if(safe[t] == 0){
		cout << "The city " << t << " is not safe!"; 
	}
	else if(res){
		cout << "The city " << t << " can arrive safely!";
	}
	else{
		cout << "The city " << t << " can not arrive safely!";
	}
	

//	for(int i = 0; i < m; i++){
//		for(auto it : road[i]){
//			cout << it << " ";
//		}
//		cout << endl;
//	}
}

void dfs(int s, int t){
	if(s == t || res){
		res = true;
		return;
	}
	for(auto it : road[s]){
		if(res) break;
		if(!book[it]){//û������ 
			book[it] = true;
			dfs(it, t);
		}
	}
}
