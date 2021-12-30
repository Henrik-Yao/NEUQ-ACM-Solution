#include<bits/stdc++.h>
using namespace std;
long long a[1000000],ans=0,temp[1000000];
void mergesort(int l,int r)
{
    if (l==r) return;
    int m = (l+r)>>1;
    mergesort(l,m);mergesort(m+1,r);
    int i = l,j = m+1,k = i;
    while (i <= m && j <= r)
        if (a[i]>a[j])
            temp[k++] = a[j++],ans+=m-i+1;
        else
            temp[k++] = a[i++];
    while (i <= m) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];
    for (int i = l;i<= r;i++)
        a[i] = temp[i];
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	cin>>a[i];
	mergesort(0,n-1);
	cout<<ans;
	return 0;
} 
