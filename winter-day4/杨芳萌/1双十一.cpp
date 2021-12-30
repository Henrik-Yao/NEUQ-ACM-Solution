#include<bits/stdc++.h>
using namespace std;
const int MIN = -0x7fffffff;
const int INF = 2147483647; 
const int N = 233;
int n,m,dist[N][N],ans[N],pos,minn;
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

void floyd() {
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) dist[i][j] = INF;
	for(int i=1; i<=n; i++) dist[i][i] = 0;
	for(int i=1; i<=m; i++) {
		int s,e,w;
		read(s), read(e), read(w);
		s++, e++;
		dist[s][e] = w;
	}
	
	for(int k=1; k<=n; k++)
		for(int a=1; a<=n; a++)
			for(int b=1; b<=n; b++)
				dist[a][b] = min(dist[a][b], dist[a][k]+dist[k][b]);		
}

void clear() {
	memset(dist,0,sizeof(dist));
	memset(ans,0,sizeof(ans));
	minn = INF;
	pos = 0;
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF) {
		clear();
		floyd();
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) ans[i] += dist[i][j];
			if(minn>ans[i]) {
				minn = ans[i];
				pos = i;
			}
		}
		printf("%d\n",pos-1);
	}
    return 0;
}

