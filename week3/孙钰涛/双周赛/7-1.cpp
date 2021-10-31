#include<iostream>
using namespace std;
int main()
{
    int n,a[10001],b[10001],MAX=-1;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(a[1]<=0) b[1]=0;
    else b[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        b[i]=max(b[i-1]+a[i],b[i]);
        MAX=max(b[i],MAX);
    }
    cout<<MAX;
    return 0;
}