#include<bits/stdc++.h>
using namespace std;
int a[1010];

int main()
{
    int n,cnt=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=1;i<n;i++)
        if(a[i]-a[i-1]==1)
            cnt++;
    cout<<cnt;
    return 0;
}
