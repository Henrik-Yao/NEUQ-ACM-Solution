#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,z,flag;
long long a[1000010],sum[4000040],add[4000040];//mid ans 在函数内定义，宏定义可能会出现冲突 
void build(int k,int l,int r){
	if(l==r){
		sum[k]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	sum[k]=sum[k*2]+sum[k*2+1];
}

void ad(int k,int l,int r,int z){
	add[k]+=z;
	sum[k]+=(r-l+1)*z;
}

void pushdown(int k,int l,int r,int mid){
	ad(k*2,l,mid,add[k]);
	ad(k*2+1,mid+1,r,add[k]);
	add[k]=0;
}

void modify(int k,int l,int r,int x,int y,int z){
	if(x<=l&&r<=y){
		ad(k,l,r,z);
		return;
	}
	int mid=(l+r)/2;
	pushdown(k,l,r,mid);
	if(x<=mid)modify(k*2,l,mid,x,y,z);
	if(y>=mid+1)modify(k*2+1,mid+1,r,x,y,z);
	sum[k]=sum[k*2]+sum[k*2+1];
}

long long query(int k,int l,int r,int x,int y){
	if(x<=l&&r<=y)
		return sum[k];
	int mid=(l+r)/2;
	long long ans=0;
	pushdown(k,l,r,mid);
	if(x<=mid)ans+=query(k*2,l,mid,x,y);
	if(y>=mid+1)ans+=query(k*2+1,mid+1,r,x,y);
	return ans;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	build(1,1,n);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&flag,&x,&y);
		if(flag==1){
			modify(1,1,n,x,x,y);
		}
		else printf("%lld\n",query(1,1,n,x,y));
	}
	return 0;
}
