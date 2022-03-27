#include <bits/stdc++.h>
using namespace std;
int n;
#define mm 10000000
long long s;
int a[mm],t[mm];
void mergesort(int r,int l,int mid)
{
   int x,y,z;
   x=r;y=r;z=mid+1;
   while (x<=mid&&z<=l)
   {
       if(a[x]<=a[z])
       t[y++]=a[x++];
       else 
       {
           s+=mid+1-x;
           t[y++]=a[z++];
       }
   }
   while(x<=mid)
   t[y++]=a[x++];
   while(z<=l)
   t[y++]=a[z++];
   for(int i=r;i<=l;i++)
   a[i]=t[i];
  
}
void merge(int r,int l)
{
    if(r<l)
    {
        int mid=(l+r)/2;
        merge(r,mid);
        merge(mid+1,l);
        mergesort(r,l,mid);
    }
}


int main()
{
    cin>>n;
    s=0;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    merge(1,n);
    
    cout<<s;
    return 0;
}