#include <bits/stdc++.h>
using namespace std;

int main ()//终于能有点成就感了
{
    int n;
    cin>>n;
    int a[n]={0};
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int cnt=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]-a[j]==1||a[i]-a[j]==-1) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}