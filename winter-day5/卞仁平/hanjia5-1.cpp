#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    int a[n];
    int s=0;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(a[i]-a[j]==1||a[i]-a[j]==-1)
                s++;
    cout<<s;
    return 0;
}