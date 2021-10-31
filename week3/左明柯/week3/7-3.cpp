#include <bits/stdc++.h>
using namespace std;
int ax[8]= {1,0,-1,-1,-1,0,1,1};
int ay[8]= {-1,-1,-1,0,1,1,1,0};
int n,m,k,l,q,w,r,t,pd[200][200],a[101][101];
void DFS(int x,int y) {
	int ma=0;
	for(int i=0; i<8; i++) {
		int xx=ax[i]+x;
		int yy=ay[i]+y;
		if(xx<1||xx>n||yy<1||yy>m)
			continue;
		if(pd[xx][yy]==1)
			ma++;
	}
	a[x][y]=ma;
	if(ma!=0)
		return;
	for(int i=0; i<8; i++) {
		int xx=ax[i]+x;
		int yy=ay[i]+y;
		if(xx<1||xx>n||yy<1||yy>m||pd[xx][yy]==1||a[xx][yy]!=-1)
			continue;
		DFS(xx,yy);
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
		DFS(r,t);
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
			cout<<"You win\n";
			return 0;
		}
		cout<<endl;
	}
}
