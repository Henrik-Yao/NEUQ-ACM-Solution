#include <bits/stdc++.h>
using namespace std;
#define N 10000000
#define ll long long 
ll sum=0; 
bool su[100000001]={0};//不能用int，否则会内存超限，还会段错误 
void sushu(ll max)
{
	su[0]=su[1]=1;
	for(ll i=2;i<=max;i++)
	{
		if(su[i]) continue;
		sum++;
		for(ll j=i*i;j<=max;j+=i)
		{
			su[j]=1;
		}
	}
}
int main()
{
	ll n;
	cin>>n;
	sushu(n);
	cout<<sum;
	return 0;
}
