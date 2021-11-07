#include<iostream>
using namespace std;;
int main()
{
    int n,m;
    cin>>n;
   while(n--)
    {
	    int i,a[41];
    	cin>>m;   	
    	a[1]=0;
    	a[2]=1;
        a[3]=2;
    	for(i=4;i<=m;i++)
    	{
    		a[i]=a[i-1]+a[i-2];
		}
		cout<<a[m]<<endl;
    }
	return 0; 
}
