#include<bits/stdc++.h>
using namespace std;
int n,m,fa[2010],cnt=0,sum=0;
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
	while(cin>>n>>m){
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		for(int i=1;i<=m;i++){
			cin>>a[i].u>>a[i].v>>a[i].w;
		}
		sort(a+1,a+m+1,cmp);
		sum=0;
		cnt=0;
		for(int i=1;i<=m;i++){
			if(findd(a[i].u)!=findd(a[i].v)){
				cnt++;
				fa[findd(a[i].u)]=findd(a[i].v);
				sum+=a[i].w;
				if(cnt==n-1)break;
			}
		}
		if(cnt==n-1){
			cout<<sum<<endl;
		}
		else{
			cout<<"There is no minimum spanning tree."<<endl;
		}
	}
	return 0;
}
