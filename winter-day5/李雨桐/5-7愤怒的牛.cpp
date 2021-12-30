#include<bits/stdc++.h>
using namespace std;

long long a[100005]={0};
long long n,m;

bool vis(int x);

int main()
{
    long long i,mid;
    cin>>n>>m;

    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    sort(a,a+n);
    long long l=a[0],r=a[n-1]-a[0];
    long long flag;

    while(l<=r)
    {
        mid=(l+r)/2;
        if(vis(mid)==true)
        {
            l=mid+1;
            flag=mid;
        }
        else
            r=mid-1;
    }

    cout<<flag<<endl;
    return 0;
}

bool vis(int x)
{
    long long cnt=1,now=a[0];
    for(long long i=1; i<n; i++)
    {
        if(a[i]-now>=x)
        {
            now=a[i];
            cnt++;
            if(cnt>=m)
            {
                return true;
            }
        }
    }
    return false;
}

