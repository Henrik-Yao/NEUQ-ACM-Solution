#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _=4e5+7;
int read() {
	int x=0,f=1;char s=getchar();
	for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
	for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
	return x*f;
}
int n,m,a[2021][2020],vis[2020][2020];
int id(int x,int y) {
	return m*(x-1)+y;
}
int fx[5]={0,0,1,-1};
int fy[5]={1,-1,0,0};
int main() {
	n=read(),m=read();
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=m;++j) {
			a[i][j]=read();
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) {
		if(!vis[i][j]&&a[i][j]==1) {
			ans++;
			queue<pair<int,int> > q;
			q.push(make_pair(i,j));
			while(!q.empty()) {
				pair<int,int> u=q.front();q.pop();
				for(int i=0;i<=3;++i) {
					int nx=u.first+fx[i],ny=u.second+fy[i];
					if(a[nx][ny]==1&&vis[nx][ny]==0&&1<=nx&&nx<=n&&1<=ny&&ny<=m) {
						vis[nx][ny]=1;
						q.push(make_pair(nx,ny));
					}
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}