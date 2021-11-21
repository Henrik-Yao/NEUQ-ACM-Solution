#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
char gender[maxn];
int visited[maxn];
vector<int> anc[maxn];
int flag=0;
void dfs(int x,int num){	
	if(num>=4) return;
	if(x==-1)  return; 
	visited[x]=true;
	for(int i=0;i<anc[x].size();i++){
		if(!visited[anc[x][i]]){
			visited[anc[x][i]]=true;
			dfs(anc[x][i],num+1); 
		}else{
			flag=1; 
		}
	}
}
 
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int id,dad,mom;
		char sex;
		cin>> id>>sex>>dad>>mom;
		gender[id]=sex;
		if(dad!=-1){
			anc[id].push_back(dad);
			gender[dad]='M';
		}
		if(mom!=-1){
			anc[id].push_back(mom);
			gender[mom]='F';
		}
	}
	int k;
	cin >>k;
	while(k--){
		int x,y;
		cin>> x>>y;
		if(gender[x]==gender[y]){
			cout<<"Never Mind"<<endl;
			continue;
		}
		memset(visited,0,sizeof(visited));
		flag=0;
		dfs(x,0);
		dfs(y,0);
		if(flag==1){
			cout<<"No"<<endl; 
		} else{
			cout<<"Yes"<<endl;
		}
	}
	return 0;	
}
