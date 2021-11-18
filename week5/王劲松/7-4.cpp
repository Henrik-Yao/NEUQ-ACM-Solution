#include<bits/stdc++.h>
using namespace std;
int m,n,j,k,a,b,sum=0;
int dy[4]={0,1,0,-1},dx[4]={-1,0,1,0};
int tu[2005][2005],vi[2005][2005];
void dfs(int x,int y);
bool ck();
int main(){
	cin>>m>>n;
	for(j=0;j<m;j++){
		for(k=0;k<n;k++){
			cin>>tu[j][k];
			if(tu[j][k])vi[j][k]=1;
		}
	}
	//a=2005,b=2005;
	while(ck()){
		dfs(a,b);
		sum++;
	}
	cout<<sum;
	return 0;
}
void dfs(int x,int y){
	vi[x][y]=0;
	int xx,yy;
	for(int i=0;i<4;i++){
		xx=x+dx[i],yy=y+dy[i];
		if(xx<0||xx>=m||yy<0||yy>=n||!vi[xx][yy]||!tu[xx][yy])continue;
		dfs(xx,yy);
	}
}
bool ck(){
	for(j=a;j<m;j++){
		for(k=0;k<n;k++){
			if(vi[j][k]&&tu[j][k]){
				a=j,b=k;
				return true;
			}
		}
	}
	return false;
}
