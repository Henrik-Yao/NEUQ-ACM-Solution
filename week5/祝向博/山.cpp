#include <bits/stdc++.h>
using namespace std;

const int maxn=2005;
const int xx[4]={1,0,-1,0};
const int yy[4]={0,1,0,-1};

int mp[maxn][maxn];
int M,N,Ans=0;

struct node {int x,y;};
queue <node> Q;

inline int read() {
	int ret=0,f=1;char ch=getchar();
	for (; !isdigit(ch); ch=getchar()) if (ch=='-') f=-f;
	for (; isdigit(ch); ch=getchar()) ret=ret*10+ch-48;
	return ret*f;
}

void bfs(node st) {
	Q.push(st),mp[st.x][st.y]=0;
	while (!Q.empty()) {
		node tp=Q.front();
		Q.pop();
		for (int f=0; f<4; ++f) {
			if (mp[tp.x+xx[f]][tp.y+yy[f]]) {
				mp[tp.x+xx[f]][tp.y+yy[f]]=0;
				Q.push((node){tp.x+xx[f],tp.y+yy[f]});
			}
		}
	}
}

int main() {
	N=read(),M=read();
	for (int i=1; i<=N; ++i)
		for (int j=1; j<=M; ++j) mp[i][j]=read();
	for (int i=1; i<=N; ++i)
		for (int j=1; j<=M; ++j) if (mp[i][j]) ++Ans,bfs((node){i,j});
	printf("%d\n",Ans);
	return 0;
}

