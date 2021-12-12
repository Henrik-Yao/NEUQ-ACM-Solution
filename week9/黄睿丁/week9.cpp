#include <iostream>
using namespace std;
int main()
{
    long long a[51];
    a[1]=1;
    a[2]=2;
    a[3]=4;
    int i;
    for(i=4;i<=50;i++)
    {
        a[i]=a[i-1]+a[i-2]+a[i-3];
    }
    int n;
    while(cin>>n)
    {
        cout<<a[n]<<endl;
    }
}