#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int a[maxn], temp[maxn];
long long cnt = 0;
void merge(int *a,int l,int r){
	if(l>=r) return;
	int mid=(l+r)>>1;
	merge(a,l, mid);
	merge(a,mid+1,r);
	int pl = l, pr=mid+1, tmpp=0;
	while(pl<= mid&&pr <= r) {
		if(a[pl]<=a[pr]) temp[tmpp++]=a[pl++];
		else temp[tmpp++] = a[pr++], cnt += mid-pl+1;
	}
	while(pl<=mid) temp[tmpp++] = a[pl++];
	while(pr<=r) temp[tmpp++] = a[pr++];
	for (int i=0; i<tmpp; i++) a[i+l]=temp[i];
} 
 
int main(){
	int n;
	cin>>n;
	for (int i=1; i<=n;i++) cin>>a[i];
	merge(a,1,n);
	cout<<cnt;
	return 0;
}
