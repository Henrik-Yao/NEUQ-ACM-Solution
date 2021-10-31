#include <bits/stdc++.h>
using namespace std;
void Merge(int a[],int l,int mid,int r){
    int i=l,j=mid+1,k=0; 
    int *temp=new int[r-l+1]; 
    while(i<=mid&&j<=r){
        if(a[i]<=a[j]) 
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    while(i<=mid)
        temp[k++]=a[i++];
    while(j<=r)
        temp[k++]=a[j++];
    for(i=l,k=0;i<=r;i++,k++)
	a[i]=temp[k];
    delete []temp;
}
void MergeSort (int a[], int l,int r) {
    if(l>=r) { return; } 
    int mid =  l + (r - l)/2; 
    MergeSort(a,l,mid);  
    MergeSort(a,mid+1,r); 
    Merge(a,l,mid,r); 
  }
  
int main ()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    MergeSort (a,0,n-1) ;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;   
}
