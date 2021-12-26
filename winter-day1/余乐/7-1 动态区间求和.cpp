#include <cstdio>
#define ll long long
using namespace std;
int n,m,x,y;
ll ans[2000001];
void build(int l,int r,int p){
	int ls=p<<1,rs=(p<<1)|1,mid=l+((r-l)>>1);
	if(l==r){scanf("%lld",&ans[p]);return;}
	build(l,mid,ls);build(mid+1,r,rs);
	ans[p]=ans[ls]+ans[rs];
}
void add(int l,int r,int p){
	int ls=p<<1,rs=(p<<1)|1,mid=l+((r-l)>>1);
	ans[p]+=y;
	if(l==r) return;
	if(x<=mid) add(l,mid,ls);
	if(mid<x) add(mid+1,r,rs);
}
ll query(int l,int r,int p){
	int ls=p<<1,rs=(p<<1)|1,mid=l+((r-l)>>1);ll sum=0;
	if(x<=l&&r<=y) return ans[p];
	if(x<=mid) sum+=query(l,mid,ls);
	if(mid<y) sum+=query(mid+1,r,rs);
	return sum;
}
int main(){
	scanf("%d%d",&n,&m);
	build(1,n,1);
	while(m--){
		int a;scanf("%d%d%d",&a,&x,&y);
		if(a==1) add(1,n,1);
		else printf("%lld\n",query(1,n,1));
	}
	return 0;
} 
