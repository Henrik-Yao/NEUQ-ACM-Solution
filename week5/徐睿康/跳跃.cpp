#include<bits/stdc++.h>
using namespace std;
int n,v,start,a[50010],vis[50010],x,flag=0,mem[50010];
queue<int>que;
void bfs(int u){
	que.push(u);
	vis[u]=1;
	while(que.size()){
		x=que.front();
		que.pop();
		if(a[x]==0){
			cout<<"True";
			flag=1;	
			break;
		}
		if(x+a[x]<n&&vis[x+a[x]]==0){
			vis[x+a[x]]=1;
			que.push(x+a[x]);
		}
		if(x-a[x]>=0&&vis[x-a[x]]==0){
			vis[x-a[x]]=1;
			que.push(x-a[x]);
		}
	}
}
/*bool dfs(int x){
	if(x==v){
		mem[x]=1;
		return true;
	}
	if(mem[x]!=-1){
		if(mem[x]==0)return false;
		else return true;
	}
	else{
		if(x-a[x]>=1){
			if(dfs(x-a[x])){
				mem[x]=1;
				return true;
			}
		}
		if(x+a[x]<=n){
			if(dfs(x+a[x])){
				mem[x]=1;
				return true;
			}
		}
		mem[x]=0;
		return false;
	}
}*/
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	cin>>start;
	bfs(start);
	if(flag!=1)cout<<"False";
	return 0;
}
