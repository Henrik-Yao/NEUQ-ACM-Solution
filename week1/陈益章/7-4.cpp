#include<iostream>
using namespace std;
int sum=0,a[10000],k=-1;
void f(int n)
{
	if (n==1)
	sum++;
	else 
	{
     	sum++;
		for (int i=1;i<=n/2;i++)
		if(n%i==0)
		a[++k]=i; 
	}
}
int main()
{
	int n;
	cin>>n;
	f(n);
	for (int i=0;i<k;i++)
	f(a[i]);
	cout<<sum+1;
	return 0;
}