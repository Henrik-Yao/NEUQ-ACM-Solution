#include<iostream>
using namespace std;
int main()
{
    int n,i;
	long long a[51];
    while(cin>>n)
    {
        a[1]=1;
        a[2]=2;
        a[3]=4;
        for(i=4;i<=n;i++)
        {
    	    a[i]=a[i-1]+a[i-2]+a[i-3];
	    }
	    cout<<a[n]<<endl;
	}
    return 0;
}
