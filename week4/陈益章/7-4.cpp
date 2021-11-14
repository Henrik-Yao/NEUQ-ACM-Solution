#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long n,a,b,c,d=1;
	cin>>n;
	for (int i=0;i<n;i++)
	{
	cin>>a>>b>>c;
	while(b>0)
	{
		if(b%2==1)
		d=(d*a)%c;
		b/=2;
		a=(a*a)%c;
	}
	cout<<d<<endl;
	d=1;
}
}
