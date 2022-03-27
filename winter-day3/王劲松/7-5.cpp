#include<bits/stdc++.h>
using namespace std;
int n,m,fa[500];
struct tu{
	int a;
	int b;
	int c;
};
tu t[20000];
bool cmp(tu a,tu b){
	return a.c <b.c ;
}
int bcj(int t){
	if(t==fa[t])return t;
	else {
		fa[t]=bcj(fa[t]);
		return fa[t];
	}
}
//int find();
int main(){
	cin>>n>>m;
	int a,b,c,cnt=0,maxx=0,i,q;
	memset(fa,0,sizeof(fa));
	for(i=1;i<=n;i++)fa[i]=i;
	for(i=1;i<=m;i++){
		cin>>a>>b>>c;
		t[i]={a,b,c};
	}
	sort(t+1,t+m+1,cmp);
	int aa,bb;
	for(i=1;cnt<n-1;i++){
		aa=bcj(t[i].a ),bb=bcj(t[i].b );
		if(aa!=bb){
			q=t[i].c ;
			maxx=max(maxx,q);
			fa[aa]=bb;
			cnt++;
		}
	}
	cout<<cnt<<" "<<maxx;
	return 0; 
}
