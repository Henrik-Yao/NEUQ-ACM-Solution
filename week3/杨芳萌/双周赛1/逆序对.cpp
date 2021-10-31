#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000001],tmp[1000001],ans;
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

void merge(int l,int r) {
	int mid = (l+r)/2;
	if(l>=r) return;
	merge(l,mid);
	merge(mid+1,r);
	int ll = l, rr = mid+1, cnt=0;
	while(ll<=mid&&rr<=r) {
		if(a[ll]<=a[rr]) tmp[cnt++] = a[ll++];
		else {
			tmp[cnt++] = a[rr++];
			ans += mid-ll+1; 
		}
	}
	while(ll<=mid) tmp[cnt++] = a[ll++];
	while(rr<=r) tmp[cnt++] = a[rr++];
	for(int i=0; i<cnt; i++) a[i+l] = tmp[i];
}

signed main(){
	read(n);
	for(int i=1; i<=n; i++) read(a[i]);
	merge(1,n);
	printf("%lld\n",ans);
    return 0;
}

