#include<bits/stdc++.h>
using namespace std;
int ans,n,t;
struct node{
	int u,v;
}a[100010];
bool cmp(node x,node y){
	return x.u<y.u;
}
void dfs(int x,int ceng){
	ans=max(ans,ceng);
	for(int i=1;i<=n;i++){
		if(a[x].v<=a[i].u){
			dfs(i,ceng+1);
		}
	}
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a[i].u,&a[i].v);
		}
		sort(a+1,a+n+1,cmp);
		ans=-1;
		for(int i=1;i<=n;i++){
			dfs(i,1);
		}
		printf("%d\n",n-ans);
	}
	return 0;
}
