#include<bits/stdc++.h>

using namespace std;

int temps[10001][10001];
bool vis[10001][10001],mapxy[10001][10001];
int n,m,sum,now,tempx[10000001],tempy[10000001],x,y,xx[4]= {1,0,-1,0},yy[4]= {0,1,0,-1};
char c;

void f(int x,int y) {
	if(vis[x][y]) 
	    return; else 
		  vis[x][y]=1;
	sum++;
	for (int i=0;i<=3;i++) {
		if(x+xx[i]>=1&&x+xx[i]<=n&&y+yy[i]>=1&&y+yy[i]<=n&&mapxy[x+xx[i]][y+yy[i]]+mapxy[x][y]==1) {
			f(x+xx[i],y+yy[i]);
		}
	}
	tempx[++now]=x;
	tempy[now]=y;
}


int main() {
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			cin>>c;
			mapxy[i][j]=c-'0';
		}
	}
	for (int i=1;i<=m;i++) {
		cin>>x>>y;
		if(temps[x][y]) {
			cout<<temps[x][y]<<endl;
		} else {
			sum=now=0;
			f(x,y);
			cout<<sum<<endl;
			for (int j=1;j<=now;j++) {
				temps[tempx[j]][tempy[j]]=sum;
			}
		}
	}
    return 0;
}

