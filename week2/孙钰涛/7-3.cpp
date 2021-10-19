#include<iostream>
using namespace std;

void guibing(int a[],int left,int right,int mid)
{
    int b[100001],i=left,j=mid+1,k=0;
    while(i<=mid && j<=right)
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
        }
    }
    while(i<=mid)
    {
        b[k]=a[i];
        k++;i++;
    }
    while(j<=right)
    {
        b[k]=a[j];
        k++;j++;
    }
    for(int i=left,k=0;i<=right;i++)
    {
        a[i]=b[k];
        k++;
    }
}

void paxu(int a[],int left,int right)
{
    if(left>=right) return ;
    int mid=(left+right)/2;
    paxu(a,left,mid);
    paxu(a,mid+1,right);
    guibing(a,left,right,mid);
}

int main()
{
    int n,a[100001];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    paxu(a,1,n);
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    return 0;
}