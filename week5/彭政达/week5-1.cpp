#include<bits/stdc++.h>
using namespace std;
#define file_in freopen("in.txt","r",stdin)
#define file_out freopen("out.txt","w",stdout)  
const int MAX=10005;
char g[MAX];
int visited[MAX];
vector<int> v[MAX];
int flag=0;
void dfs(int x,int num){
	if(num>=4) return;
	visited[x]=true;
	for(int i=0;i<v[x].size();i++){
		if(!visited[vec[x][i]]){
			visited[vec[x][i]]=true;
			dfs(v[x][i],num+1);
		}
		else flag=1;
	}
}
int main(){
	file_in;
	file_out;
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++){
		int id,fa,mo;
		char sex;
		cin>>id>>sex>>fa>>mo;
		g[id]=sex;
		if(fa!=-1){
			v[id].push_back(fa);
			g[fa]='M';
		}
		if(mother!=-1){
			v[id].push_back(mo);
			g[mo]='F';
		}
	}
	cin>>m;
	for(int i=0;i<m-1;i++){
		int x,y;
		cin>> x>>y;
		if(g[x]==g[y]){
			cout<<"Never Mind"<<endl;
			continue;
		}
		flag=0;
		memset(visited,0,sizeof(visited));
		dfs(x,0);dfs(y,0);
		if(flag==1) cout<<"No"<<endl; 
		else cout<<"Yes"<<endl;
	}
    int x,y;
    cin>> x>>y;
		if(g[x]==g[y]){
			cout<<"Never Mind";
			return 0;
		}
		flag=0;
		memset(visited,0,sizeof(visited));
		dfs(x,0);dfs(y,0);
		if(flag==1) cout<<"No"; 
		else cout<<"Yes";
	return 0;
}
