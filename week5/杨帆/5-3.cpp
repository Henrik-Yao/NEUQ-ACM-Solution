#include<bits/stdc++.h>
using namespace std;
const int k = 20005;
vector <int> vec[k];
bool vis[k];
int ans[k];
int p = 0;

void dfs(int x){
    vis[x] = 1;
    ans[++p] = x;
    for(int i=0; i<vec[x].size(); i++){
    	int temp = vec[x][i];
    	if(vis[temp]){
    		continue;
		}
		dfs(temp);
	}
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int a,b;
        cin >> a >> b;
        vec[a].push_back(b);
    }
    for(int i=0; i<n; i++){
        sort(vec[i].begin(),vec[i].end());
    }
    for(int i=0; i<n; i++){
    	if(!vis[i]){
    		dfs(i);
		}
	}
	for(int i=1; i<=p; i++){
		cout << ans[i] << " ";
	}
    return 0;
}
