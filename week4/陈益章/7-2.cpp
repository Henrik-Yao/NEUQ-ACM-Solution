#include<iostream>
using namespace std; 
int main()
{
	int n,m,a[41];
	a[1]=1;a[2]=2;a[0]=0;
	cin>>n;
	for (int j=3;j<=40;j++)
		{
			a[j]=a[j-1]+a[j-2]	;
		}
	for (int i=0;i<n;i++)
	{
		cin>>m;
		cout<<a[m-1]<<endl;
	}
    return 0;
}