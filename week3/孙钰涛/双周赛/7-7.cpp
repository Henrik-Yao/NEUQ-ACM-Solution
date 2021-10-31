#include<iostream>
#include<algorithm>
using namespace std;
long long num=0;
long long b[1000001],a[1000001];
void merge(long long l,long long r,long long mid)
{
    long long i=l,j=mid+1,k=0;
    while(i<=mid && j<=r)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            k++;i++;
        }
        else
        {
            b[k]=a[j];
            k++;j++;
            num=num+mid-i+1;
        }
    }
    while(i<=mid)
    {
        b[k]=a[i];
        k++;i++;
    }
    while(j<=r)
    {
        b[k]=a[j];
        k++;j++;
    }
    for(int i=l,j=0;i<=r;i++)
    {
        a[i]=b[j];
        j++;
    }
}

void merge_sort(long long l,long long r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        merge_sort(l,mid);
        merge_sort(mid+1,r);
        merge(l,r,mid);
    }
}

int main()
{
    long long n;
    cin>>n;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    merge_sort(0,n-1);
    cout<<num;
    return 0;
}