#include<iostream>
#define ll long long
using namespace std;
int n;
ll a[55];
int main()
{
	a[1]=1,a[2]=2,a[3]=4;
	for(int i=4;i<=50;i++)
	a[i]=a[i-1]+a[i-2]+a[i-3];
    while(cin>>n)
    {
    	cout<<a[n]<<endl;
	}
}
