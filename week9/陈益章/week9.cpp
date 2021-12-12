#include<iostream>
using namespace std;
int main()
{
	long long int n,a[50],sum=0;
	while(cin>>n)
	{
	a[1]=1;a[2]=2;a[3]=4;
	if (n<=3)
	cout<<a[n]<<endl;
	else
	{
		for (int i=0;i<n-3;i++)
	{
	sum=a[1]+a[2]+a[3];
	a[1]=a[2];
	a[2]=a[3];
	a[3]=sum;
	}
	cout<<sum<<endl; 
	sum=0;
}	
}
}
