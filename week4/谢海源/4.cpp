#include<bits/stdc++.h>
using namespace std;
#define ll long long
void f(ll a,ll b,ll c)
{
	ll x=1;
	while(b>0)
	{//位运算比普通求余速度更快
		if(b&1==1)x=x*a%c;//b为奇数时，落单的数直接相乘求余(b&1==1相当于b%2==1)
		a=a*a%c;//a进行平方减少幂次
		b=b>>1;//幂次减少(相当于b=b/2)
	}
	cout<<x<<endl;
	return;
}
int main()
{
	ll t,a,b,c;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c;
		f(a,b,c);
	}
	return 0;
}
