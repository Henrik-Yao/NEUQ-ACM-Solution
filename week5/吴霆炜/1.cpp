#include <bits/stdc++.h>
using namespace std;
#define maxn 100010

struct people{
	char gender;
	int dad = -1;
	int mom = -1;
}p[maxn];

int n;
bool flag;
bool vis[maxn];
void dfs(int v,int cnt){
	if(vis[v]){
		flag = true;
		return;
	}
	vis[v] = true;
	if(cnt == 5)
	return;
	if(p[v].dad != -1)
	dfs(p[v].dad,cnt + 1);
	if(p[v].mom != -1)
	dfs(p[v].mom,cnt + 1);
}

int main(){
	//freopen("data.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		int no;
		cin>>no;
		cin>>p[no].gender>>p[no].dad>>p[no].mom;
		p[p[no].dad].gender = 'M';
		p[p[no].mom].gender = 'F';

	}
	int k;
	cin>>k;
	for(int i = 1;i <= k;i++){
		int no1,no2;
		cin>>no1>>no2;
		if(p[no1].gender == p[no2].gender){
		puts("Never Mind");
		}
		else{
		memset(vis,0,sizeof(vis));
		flag = false;
		dfs(no1,1);
		dfs(no2,1);
		if(!flag)
			puts("Yes");
		else
			puts("No");
	}}
	return 0;
}