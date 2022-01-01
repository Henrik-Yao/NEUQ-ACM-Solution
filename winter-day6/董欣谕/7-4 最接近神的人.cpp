#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int n,a[500005],b[500005];
ll cnt=0;
void merge_sort(int l,int r,int *A) {
	if (l>=r) return;
	int mid=(l+r)>>1;
	merge_sort(l,mid,A);
	merge_sort(mid+1,r,A);
	int pl=l, pr=mid+1,temp=0;
	while(pl<=mid&&pr<=r){
		if (A[pl]<=A[pr]) b[temp++]=A[pl++];
		else b[temp++]=A[pr++],cnt+=mid-pl+1;
	}
	while(pl<=mid) b[temp++]=A[pl++];
	while(pr<=r) b[temp++]=A[pr++];
	for (int i=0; i<temp;i++) A[i+l]=b[i];
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	merge_sort(1,n,a);
	cout<<cnt;
	return 0;
}