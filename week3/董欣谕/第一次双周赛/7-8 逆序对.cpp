#include <bits/stdc++.h>
using namespace std;
int a[1000001];
int temp[1000001];
long long ans=0;
void merge(int l,int r) {
	if (l>=r) return;
	int mid=(l+r)>>1;
	merge(l,mid);
	merge(mid+1,r);
	int i=l,j=mid+1,k=0;
	while (i<=mid&&j<=r) {
		if (a[i]<=a[j]) temp[k++]=a[i++];
		else {
			temp[k++]=a[j++];
			ans+=mid-i+1;
		}
	}
	while (i<=mid) temp[k++]=a[i++];
	while (j<=r) temp[k++]=a[j++];
	for (i=l,j=0; i<=r; i++,j++)
		a[i]=temp[j];
}

int main() {
	int n;
	cin>>n;
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	merge(1,n);
	cout<<ans;
	return 0;
}
