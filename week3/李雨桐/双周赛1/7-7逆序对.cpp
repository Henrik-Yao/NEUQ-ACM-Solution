#include <bits/stdc++.h>
using namespace std;

int a[1000000],temp[1000000];
long long num=0;
void mer(int l,int r)
{
    if(l==r)
        return;
    int m=(l+r)/2;
    mer(l,m); mer(m+1,r);
    int p=l,q=m+1,now=0;

    while(p<=m && q<=r)
    {
        if(a[p]<=a[q])
        {
            temp[now++] = a[p++];
        }
        else
        {
            temp[now++] = a[q++];
            num += (m-p+1);
        }
    }

    while(p<=m)
        {
            temp[now++] = a[p++];
        }

    while(q<=r)
    {
        temp[now++] = a[q++];
    }

    for(int i=l;i<=r;i++)
    {
        a[i] = temp[i-l];
    }

}
int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    mer(1,n);

    cout<<num;


	return 0;
}
