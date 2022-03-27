#include<bits/stdc++.h>
using namespace std;
int n,dep[1010],T,root,cun[1010],flag=0,maxx;
struct node{
	int l,r;
}a[1010];
/*int poww(int x,int y){
	int sum=1;
	for(int i=1;i<=y;i++)sum*=x;
	return sum;
}
int log(int x){
	for(int i=1;i<=10;i++)
	if(poww(2,i)-1>=x)return i;
}*/
void build(int root,int xu){
	if(xu*2<=n){
		a[root].l=cun[xu*2];
		build(cun[xu*2],xu*2);
	}
	else a[root].l=0;
	if((xu*2)+1<=n){
		a[root].r=cun[(xu*2)+1];
		build(cun[(xu*2)+1],(xu*2)+1);
	}
	else a[root].r=0;
}
void dfs1(int fa,int x){
	dep[x]=dep[fa]+1;
	maxx=max(maxx,dep[x]);
	if(a[x].l!=0)dfs1(x,a[x].l);
	if(a[x].r!=0)dfs1(x,a[x].r);
}
void dfs(int x){
	if(a[x].l!=0)dfs(a[x].l);
	if(flag==0){
		flag=1;
		cout<<x;
	}
	else cout<<' '<<x;
	if(a[x].r!=0)dfs(a[x].r);
}
int main(){
	cin>>T;
	while(T--){
		memset(dep,0,sizeof(dep));
		maxx=-1;
		flag=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>cun[i];
		root=cun[1];
		build(root,1);
		dfs1(0,root);
		dfs(root);
		cout<<endl<<maxx<<endl;
	}
	return 0;
}
