#include<bits/stdc++.h>
using namespace std;

long long MergeSort(long long a[],long long l,long long m,long long r)
{
    long long i,j;
    i=l;
    j=m;
    long long b[r-l+1];
    long long loca=0;
    long long sum=0;
    long long t=0;

    while(i<m&&j<=r)
    {
        if(a[i]>a[j])
        {
            b[loca++] = a[j++];
            t++;
        }
        if(a[i]<=a[j]||j==r+1)
        {
            sum=sum+t*(m-i);
            b[loca++]=a[i++];
            t=0;
        }
    }

    while(i<m)
    {
        b[loca++]=a[i++];
    }
    while(j<=r)
    {
        b[loca++]=a[j++];
    }
    loca=0;
    long long x;
    for(x=l;x<=r;x++)
    {
        a[x]=b[loca++];
    }
    return sum;
}

long long co;

void Merge(long long a[],long long l,long long r)
{
    if(l<r)
    {
        long long mid=(l+r)/2;
        Merge(a,l,mid);
        Merge(a,mid+1,r);
        co=co+MergeSort(a,l,mid+1,r);
    }
}

long long a[1000010];
int main()
{
    long long n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    Merge(a,0,n-1);
    cout<<co;
}
