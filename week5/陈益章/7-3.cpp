#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> a[20010];
int vis[20010]; 
int n,e,sum;
void dfs(int x){
	int i;
	cout<<x<<" ";
	vis[x] = 1;
	int len = a[x].size();
	for(int i = 0;i<len;i++){
		if (vis[a[x][i]]==0)
			dfs(a[x][i]);                                                                                             
	}
}
int main(){
	
	int b1,b2;
	cin>>n>>e;
	for(int i = 0;i<e;i++)
	{
		cin>>b1>>b2;
		a[b1].push_back(b2);
	}
	for(int i = 0;i<n;i++)
		sort(a[i].begin(),a[i].end());
	for(int i = 0;i<n;i++)
		if(vis[i] == 0)
			dfs(i);
	return 0; 
}
