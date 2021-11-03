#include <bits/stdc++.h>
using namespace std;
int Safe[101],arcs[101][101],vis[101];
int m,n,k;
int p;
int s,d;
void dfs(int s){
	vis[s]=1;
	if(s==d) p=1;
	for(int i=0;i<m;i++){
		if((arcs[s][i]==1||arcs[i][s]==1)&&Safe[i]==1){
			dfs(i);
			vis[s]=0;
		}
	}
	return;
}
int main(){
	cin>>m>>n>>k;
	while(n--){
		int safe;
		cin>>safe;
		Safe[safe]=1;
	}
	while(k--){
		int i,j;
		cin>>i>>j;
		arcs[i][j]=1;
		arcs[j][i]=1;
	}
	cin>>s>>d;
	if(Safe[d]==0) cout<<"The city "<<d<<" is not safe!";
	else{
		dfs(s);
		if(p) cout<<"The city "<<d<<" can arrive safely!";
		else cout<<"The city "<<d<<" can not arrive safely!";
	}
	return 0;
}



