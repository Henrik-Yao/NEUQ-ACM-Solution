#include<bits/stdc++.h>
using namespace std;
int n,cnt,first[23333],e;
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}
struct edge{
	int e,w;
}; 
vector<edge> G[23333];
void addedge(int s,int e,int w){
	edge e1;
	e1.e = e;
	e1.w = w;
	G[s].push_back(e1);
}

bool cmp(edge a, edge b) {
	return a.e<b.e;
}

int main(){
	read(n), read(e);
	for(int i=1; i<=e; i++) {
		int s,e,w;
		read(s),read(e),read(w);
		addedge(s,e,w);
	}
	for(int i=0; i<n; i++) sort(G[i].begin(),G[i].end(),cmp);
	for(int i=0; i<n; i++) 
		if(G[i].size() != 0) {
			printf("%d:",i);
			for(int j=0; j<G[i].size(); j++)
				printf("(%d,%d,%d)",i,G[i][j].e,G[i][j].w);
			printf("\n");
		}
    return 0;
}

