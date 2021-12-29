#include<bits/stdc++.h>
using namespace std;
#define N 110
int n,m,dis[N][N],sta[N],qian[N][N],maxx,flagx,flagy,top,x,y,z,pan[N];
priority_queue<pair<int,int> >que;
vector<pair<int,int> >vec[N];
void dfs(int x,int y){
	sta[++top]=y;
	if(qian[x][y]!=y)
	dfs(x,qian[x][y]);
}
void print(int x,int y){
	top=0;
	dfs(x,y);
	for(int i=top;i>=1;i--){
		if(i==top)printf("%d",sta[i]);
		else printf("->%d",sta[i]);
	}
}
/*void dij(int xx){
	for(int i=0;i<n;i++)pan[i]=0;
	que.push(make_pair(0,xx));
	while(que.size()){
		int u=que.top().second;
		que.pop();
		if(pan[u])continue;
		pan[u]=1;
		for(int i=0;i<vec[u].size();i++){
			int v=vec[u][i].first,w=vec[u][i].second;
			if(dis[xx][v]>dis[xx][u]+w){
				dis[xx][v]=dis[xx][u]+w;
				que.push(make_pair(-dis[xx][v],v));
				qian[xx][v]=u;
			}
		}
	}
}*/
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dis[i][j]=1e9;
			qian[i][j]=i;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		dis[x][y]=z;
	}
	
	for(int k=0;k<n;k++){
		for(int j=0;j<n;j++){
			for(int i=0;i<n;i++){
				if(dis[i][j]>dis[i][k]+dis[k][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
					qian[i][j]=qian[k][j];
					//qian[i][j]=qian[i][j]从起点开始正序输出 
				}
			}
		}
	}
	for(int i=1;i<=2;i++){
		cin>>x>>y;
		if(x==y){
			printf("%d->%d:0\n",x,y);
		}
		else if(dis[x][y]==1e9){
			printf("%d->%d:-1\n",x,y);
		}
		else{
			print(x,y);
			cout<<':'<<dis[x][y]<<endl;
		}
	}
	maxx=-1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(dis[i][j]>maxx&&dis[i][j]!=1e9){
				maxx=dis[i][j];
				flagx=i;
				flagy=j;
			}
		}
	}
	print(flagx,flagy);
	cout<<':'<<dis[flagx][flagy];
	return 0;
}
