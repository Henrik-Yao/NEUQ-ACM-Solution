#include <iostream>
using namespace std;
int a[1000001],mid,t;
void chazhao(int l,int r)
{
	if(a[r]>=t&&a[r-1]<t)
	{
		cout<<mid<<endl;
		return;
	}
	mid=(l+r)/2;
	if(a[mid]>=t) chazhao(l,mid);
	else if(a[mid]<t) chazhao(mid,r);
	
}
int main()
{
	int n;
	cin>>n>>t;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(a[n]<t) cout<<n+1<<endl;
	else chazhao(1,n);
	return 0;
}
