#include<iostream>
#include<queue>
using namespace std;
int a[1000001];
int mmax[1000001];
int main()
{
    int n,k,step=0,now=1;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    mmax[1]=a[1]+1;
    for(int i=2;i<=n;i++)
        mmax[i]=max(mmax[i-1],a[i]+i);
    while(1)
    {
        now=mmax[now];
        step++;
        if(now>=n) break;
    }
    cout<<step;
    return 0;
}