#include<iostream>
using namespace std;

int m[51000];
int n,start,k;
int vs[51000]={0};

int dfs(int i){
	k=0;
	if(i>=n || i<0) return 0;
	if(m[i] == 0) return 1;
	if(vs[i] == 0){
		vs[i] = 1;
		k = dfs(i+m[i]);
		if(k == 1) return 1;
		k = dfs(i-m[i]);
		if(k == 1) return 1;
	}
	return 0;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> m[i];
	}
	cin >> start;
	k = dfs(start);
	if(k == 1) cout << "True";
	else cout << "False";
	
	
	return 0;
}
