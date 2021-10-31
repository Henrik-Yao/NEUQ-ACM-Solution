#include <iostream>
using namespace std;
void mergesort(int a[],int l,int r,int mid)
{
     int i=l,j=mid+1,k=0;
    int *temp=new int[r-l+1];
    while(i<=mid&&j<=r)
    {
        if(a[i]<=a[j]) temp[k++]=a[i++];
        else temp[k++]=a[j++];
    }
    while (i<=mid) temp[k++]=a[i++];
    while (j<=r) temp[k++]=a[j++];
    for(i=l,k=0;i<=r;i++,k++) a[i]=temp[k];
    delete []temp;
}
void merge(int a[],int l,int r)//¸´Ï°Ò»ÏÂ¹é²¢ÅÅÐò
{
    if(l>=r) return ; 
    int mid=l+(r-l)/2;
    merge (a,l,mid);
    merge (a,mid+1,r);
    mergesort(a,l,r,mid);
}

int main ()
{
    int t,a,b,c;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>a;
        int x[a];
        for(int j=0;j<a;j++)
        {
            cin>>x[j];
        }
        cin>>b;
        int y[b];
        for(int j=0;j<b;j++)
        {
            cin>>y[j];
        }
        c=a+b;
        int aa[c];
 for(int j=0;j<a;j++)
        {
            aa[j]=x[j];
        }
         for(int j=0,k=a;j<b;j++,k++)
        {
            aa[k]=y[j];
        }
		int l=0,r=c;
    merge(aa,l,r);
    for(int i=0;i<c;i++)
    {
        if(i<c-1) cout<<aa[i]<<" ";
        else cout<<aa[i]<<endl;
    }
       
    }
    
    return 0;
    
}
