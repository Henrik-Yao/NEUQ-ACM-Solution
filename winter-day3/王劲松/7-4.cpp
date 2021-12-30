#include<bits/stdc++.h>
using namespace std;
int t[100][100],sum=0;
int n,m,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
void f(int x,int y);
int main(){
	cin>>n>>m;
	for(int j=1;j<=n;j++){
		for(int k=1;k<=m;k++){
			cin>>t[j][k];
			
		}
	}
	for(int j=1;j<=n;j++){
		for(int k=1;k<=m;k++){
			if(t[j][k])f(j,k),sum++;
		}
	}
	cout<<sum;
	return 0;
}
void f(int x,int y){
	t[x][y]=0;
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx<1||yy<1||xx>n||yy>m||t[xx][yy]==0)continue;
		f(xx,yy);
	} 
}
