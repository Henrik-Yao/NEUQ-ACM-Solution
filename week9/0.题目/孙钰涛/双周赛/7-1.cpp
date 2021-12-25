#include<iostream>
#include<algorithm>
using namespace std;
int a[202112621];
int gap[202112621];

int main()
{
    int n,m,s_min;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    sort(a+1,a+n+1);
    s_min=a[n]-a[1]+1;
    for(int i=1;i<n;i++)
    {
        gap[i]=a[i+1]-a[i]-1;
    }
    sort(gap+1,gap+n);
    for(int i=n-1;i>n-m;i--)
        s_min=s_min-gap[i];
    cout<<s_min;
    return 0;
}