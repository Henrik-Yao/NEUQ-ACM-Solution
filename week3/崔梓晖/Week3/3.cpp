#include <bits/stdc++.h>
using namespace std;
int fx[8]= {1,0,-1,-1,-1,0,1,1};
int fy[8]= {-1,-1,-1,0,1,1,1,0};
int n,m,k,l,q,w,r,t,pd[101][101],a[101][101];
void dfs(int x,int y) {
	int da=0;
	for(int i=0; i<8; i++) {
		int xx=fx[i]+x;
		int yy=fy[i]+y;
		if(xx<1||xx>n||yy<1||yy>m)
			continue;
		if(pd[xx][yy]==1)
			da++;
	}
	a[x][y]=da;
	if(da!=0)
		return;
	for(int i=0; i<8; i++) {
		int xx=fx[i]+x;
		int yy=fy[i]+y;
		if(xx<1||xx>n||yy<1||yy>m||pd[xx][yy]==1||a[xx][yy]!=-1)
			continue;
		dfs(xx,yy);
	}
}
int main() {
	memset(a,-1,sizeof a);
	cin>>n>>m>>k>>l;
	for(int i=1; i<=k; i++) {
		cin>>q>>w;
		q++;
		w++;
		pd[q][w]=1;
	}
	for(int i=1; i<=l; i++) {
		cin>>r>>t;
		r++;
		t++;
		if(pd[r][t]==1) {
			cout<<"You lose";
			return 0;
		}
		if(a[r][t]!=-1)
			continue;
		dfs(r,t);
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
		int ans=0;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				if(a[i][j]==-1)
					ans++;
			}
		}
		if(ans==k) {
			cout<<"You win";
			return 0;
		}
		cout<<endl;
	}
}

