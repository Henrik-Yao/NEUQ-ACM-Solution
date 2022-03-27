#include <iostream>
using namespace std;

int n;
int a[100005],temp[100005];

void merge_sort(int l,int r)
{
    if(l>=r)
        return;

    int mid=(l+r)/2;
    merge_sort(1,mid);
    merge_sort(mid+1,r);

    int p=l,q=mid+1,now=1;
    while(p<=mid && q<=r)
    {
        if(a[p]<a[q])
             temp[now++]=a[p++];

        else
            temp[now++]=a[q++];

    }

         while(q<=r)
    {
        temp[now++]=a[q++];
    }

        while(p<=mid)
    {
        temp[now++]=a[p++];
    }


    for(int i=l,j=1;i<=r;i++,j++)
    {
        a[i]=temp[j];
    }
}

int main()
{

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    merge_sort(1,n);

    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<' ';
    }
}
