#include <bits/stdc++.h>
using namespace std;
struct node{
int from,to;
int dis;
friend bool operator <(node A,node B){
	return A.dis<B.dis;
}	
}hh[20001],s[20001];
int n,m;
int p[1000];
int findth(int x){
	if(x==p[x]) return x;
	return p[x]=findth(p[x]);
}

void unionn(int x,int y){
	int xx=findth(x);
	int yy=findth(y);
	if(xx!=yy) p[yy]=xx;
}
int cnt=0;
void kruskal(){
	sort(hh+1,hh+1+m);
	for(int i=1;i<=m;i++){
		if(findth(hh[i].from)==findth(hh[i].to)) continue;
		unionn(hh[i].from,hh[i].to);
		cnt++;
		s[cnt].from=hh[i].from;
		s[cnt].to=hh[i].to;
		s[cnt].dis=hh[i].dis;
	}
}


int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d %d %d",&hh[i].from,&hh[i].to,&hh[i].dis);
	}
	kruskal();
	sort(s+1,s+1+cnt);
	printf("%d %d",cnt,s[cnt].dis);
	
	
	return 0;
}
