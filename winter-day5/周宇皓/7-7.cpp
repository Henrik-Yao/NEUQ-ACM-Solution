#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,a[N];
bool check(int x)
{
    int now=a[1],cnt=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]-now>=x)
        {
            now=a[i];
            cnt++;
        }
    }
    if(cnt>=m) return true;
    else return false;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int l=0,r=1e5;
    while (l<r)
    {
        int m=(l+r+1)/2;
        if(check(m)) l=m;
        else r=m-1;
    }    
    cout<<l<<endl;
    return 0;
}
