#include<bits/stdc++.h>
using namespace std;

int m[50001];
bool book[50001] = {false};
bool isend = false;
int n, start;

void dfs(int now){
	if(isend || now < 0 || now >= n || book[now]) return;
	if(m[now] == 0){
		isend = true;
		return;
	}
	book[now] = true;
	dfs(now + m[now]);
	dfs(now - m[now]);
}


int main() {
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> m[i];
	}
	cin >> start;
	dfs(start);
	if(isend){
		cout << "True";
	}
	else{
		cout << "False";
	}
}
