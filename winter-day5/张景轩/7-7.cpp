#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
 
typedef long long ll;
ll x[100001];
ll a[100001];
ll n,m;

bool check(ll X){
	ll bf=x[0],total=1;
	ll i;
	for(i=1;i<n;i++)
    {
		if(x[i]-bf>=X)
        {
			total++;
			bf=x[i];
		}
		if(total>=m)return true;
	}
	return false;
}
 
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
    {
		scanf("%lld",x+i);
	}
	sort(x,x+n);

	ll minn=99999;

	for(ll i=1;i<n;i++)
    {
		minn=min(x[i]-x[i-1],minn);
	}
	ll l=minn,r=x[n-1]-x[0];
	 
	while(l<=r)
    {
		ll mid=(l+r)>>1;
		if(check(mid))
        {
            l=mid+1;
        }
		else
        {
            r=mid-1;
        }
	}
	cout<<r<<endl;

	return 0;
}
