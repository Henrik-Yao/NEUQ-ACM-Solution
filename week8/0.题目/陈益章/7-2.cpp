#include<iostream>
using namespace std;
int a[1000000];
int mmax[1000000];
int main()
{
    int n,k,x=0,w=1;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    mmax[1]=a[1]+1;
    for(int i=2;i<=n;i++)
        mmax[i]=max(mmax[i-1],a[i]+i);
    while(1)
    {
        w=mmax[w];
        x++;
        if(w>=n) break;
    }
    cout<<x;
    return 0;
} 
