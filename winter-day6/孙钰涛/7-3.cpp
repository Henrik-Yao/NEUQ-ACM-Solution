#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[51]={0},n,x;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>x,a[x]++;
    for(int i=0;i<=50;i++)
        if(a[i]) cout<<i<<":"<<a[i]<<"\n";
    return 0;
}