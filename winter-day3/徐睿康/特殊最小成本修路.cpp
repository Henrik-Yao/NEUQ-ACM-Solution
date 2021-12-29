#include<bits/stdc++.h>
using namespace std;
int n,m,fa[310],cnt=0,cun=0,q,sum=0;
struct node{
	int u,v,w;
}a[100010];
bool cmp(node x,node y){
	return x.w<y.w;
}
int findd(int x){
	if(fa[x]==x)return x;
	else return fa[x]=findd(fa[x]);
}
int main(){
	while(cin>>n>>q>>m){
		cnt=0;
		cun=0;
		sum=0;
		for(int i=1;i<=m;i++){
			cin>>a[i].u>>a[i].v>>a[i].w;
		}
		sort(a+1,a+m+1,cmp);
		for(int i=0;i<n;i++)fa[i]=i;
		for(int i=1;i<=m;i++){
			if(findd(a[i].u)!=findd(a[i].v)){
				if(a[i].u==q||a[i].v==q){
					if(cun>=2)continue;
					cun++;
				}
				cnt++;
				fa[findd(a[i].u)]=findd(a[i].v);
				sum+=a[i].w;
				if(cnt==n-1)break;
			}
		}
		if(cnt==n-1)cout<<sum<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
