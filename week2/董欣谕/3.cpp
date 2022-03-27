#include <bits/stdc++.h>
using namespace std;
int tmp[100001],a[100001],ans=0;
void merge(int l,int r) {
	if (l>=r) return;
	int mid=(l+r)/2;
	merge(l,mid);
	merge(mid+1,r);
	int k=0,i=l,j=mid+1;
	while (i<=mid&&j<=r)
		if (a[i]<a[j]) tmp[k++]=a[i++];
		else tmp[k++]=a[j++];
	while (i<=mid) tmp[k++]=a[i++];
	while (j<=r) tmp[k++]=a[j++];
	for (i=l,j=0; i<=r; i++,j++) a[i]=tmp[j];
}

int main() {
	int n,i;
	cin>>n;
	for (i=1; i<=n; i++)
		cin>>a[i];
	merge(1,n);
	for (i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
}
