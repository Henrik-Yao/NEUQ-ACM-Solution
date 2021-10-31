#include<iostream>
using namespace std;
int a[1000000];
int main()
{
    int n,x;
    cin>>n>>x;
    for(int i=1;i<=n;i++) 
	cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=x)
        {
            cout<<i;
           return 0;
        }
    }
	cout<<n+1;
    return 0;
}
