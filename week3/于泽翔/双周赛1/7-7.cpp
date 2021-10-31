#include <bits/stdc++.h>
using namespace std;
int a[1000010], b[1000010], n;
long long ans;

void msort(int l, int r)
{
	int mid=(l+r)/2, i, j, k=l;
	i=l;
	j=mid+1;
	
	if(l==r)
		return;
	
	msort(l, mid);
	msort(mid+1, r);
	
	while(i<=mid&&j<=r)
		if(a[i]<=a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++], ans+=mid-i+1;
	
	while(i<=mid)
		b[k++]=a[i++];
	while(j<=r)
		b[k++]=a[j++];
	
	for(int ij=l; ij<=r; ij++)
		a[ij]=b[ij];
}
int main(void)
{
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	msort(1, n);
	cout<<ans;
	
	return 0;
}