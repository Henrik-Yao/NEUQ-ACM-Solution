#include <bits/stdc++.h>
#define lowbit(i) (i&(-i))
using namespace std;
const int N=1234567;
long long a[N]={0};
void update(int i,int y,int n)
{
	for(;i<=n;i+=lowbit(i))	a[i]+=y;
}
long long getsum(int i)
{
	long long sum=0;
	for(;i;i-=lowbit(i))
		sum+=a[i];
	return sum;
 } 
int main()
{
	long long n,q,l,r,b,c,i;
	cin>>n>>q;
	for(i=1;i<=n;i++)
	{
		cin>>b;
		update(i,b,n);
	}
	while(q--)
	{
		cin>>c>>l>>r;
		if(c==1) update(l,r,n);
		else	cout<<getsum(r)-getsum(l-1)<<endl;
	}
	return 0;
} 
