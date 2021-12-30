#include<bits/stdc++.h>
using namespace std;
int a[101];

int find(int x,int l,int r)
{
    while (l<=r)
    {
        int mid=(l+r)/2;
        if(x==a[mid]) return mid;
        if(x>a[mid]) l=mid+1;
        else r=mid-1;
    }
    return 0;
}
bool find_ans0(int x)
{
	int a[132],n;
    int m,cnt=m,temp=a[1]+x;
    cnt--;
    for(int i=2;i<=n;i++)
    {
        if(temp<=a[i])
        {
            cnt--;
            temp=a[i]+x;
        }
    }
    if(cnt<=0) return 1;
    else return 0;
}
int main()
{
    int n,m,x;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)
        {
            cout<<a[i];
            if(i!=n) cout<<" ";
        }
        cout<<"\n";
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            cin>>x;
            cout<<find(x,1,n);
            if(i!=m) cout<<" ";
        }
        cout<<"\n";
    }/////////////
}
