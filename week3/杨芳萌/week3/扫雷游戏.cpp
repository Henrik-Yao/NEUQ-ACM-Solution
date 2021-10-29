#include<bits/stdc++.h>
using namespace std;
const int N = 233;
int n,m,k,l,a[N][N];
int dx[8] = {-1,-1,-1, 0,0, 1,1,1};
int dy[8] = {-1, 0, 1,-1,1,-1,0,1};
bool vis[N][N];
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

void bfs(int x,int y) {
	if(x>=n||y>=m||x<0||y<0) return;
	if(a[x][y]!=0) return;
	for(int i=0; i<8; i++) {
		if(vis[x+dx[i]][y+dy[i]]==0) {
			vis[x+dx[i]][y+dy[i]] = 1;
			bfs(x+dx[i],y+dy[i]);
		}
	}
	return; 
} 

void Print() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(vis[i][j]) cout<<a[i][j]<<' ';
			else cout<<"-1 ";
		}
		cout<<endl;
	}		
}

int main(){
	read(n), read(m), read(k), read(l);
	for(int i=0; i<k; i++) {
		int xx,yy;
		read(xx), read(yy);
		a[xx][yy] = -1;
		for(int i=0; i<8; i++)
			if(xx+dx[i]>=0&&yy+dy[i]>=0)
				if(a[xx+dx[i]][yy+dy[i]]!=-1) 
					a[xx+dx[i]][yy+dy[i]]++;
	}
	for(int i=0; i<l; i++) {
		int xx,yy;
		read(xx), read(yy);
		if(vis[xx][yy]) continue;
		vis[xx][yy] = 1;
		if(a[xx][yy]==-1) {
			cout<<"You lose"<<endl;
			break;
		} else {
			bfs(xx,yy);
			Print();
			bool judge = 0;
			for(int i=0; i<n; i++) 
				for(int j=0; j<n; j++) 
					if(vis[i][j]==0&&a[i][j]!=-1) {
						judge = 1;
						break;
					} 
			if(judge==0) {
				cout<<"You win"<<endl;
				break;
			}
		}
		puts("");
	}
    return 0;
}

