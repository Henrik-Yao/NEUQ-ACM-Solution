#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+6;
int n,q,a[N],ans=-1;
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

void erfen(int l,int r) {
	int mid = (l+r)/2;
	if(l>=r) return;
	if(a[mid]>=q) {
		ans = mid;
		erfen(l,mid-1);
	} else erfen(mid+1,r);
	return;
}
int main(){
	read(n),read(q);
	for(int i=1; i<=n; i++) read(a[i]);
	erfen(1,n);
=	if(ans==-1) printf("%d\n",n+1);
	else printf("%d\n",ans);
    return 0;
}
