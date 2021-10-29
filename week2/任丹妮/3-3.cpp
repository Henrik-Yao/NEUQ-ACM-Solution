#include <iostream>
using namespace std;
    long long a[100001];
    long long temp[100001];
void merge(long long a[],int first,int mid,int last){
    int k=0;
    int i=first;
    int j=mid+1;
    while(i<=mid&&j<=last){
        if(a[i]<a[j]) {
            temp[k++]=a[i];
            i++;
        }
        else {
            temp[k++]=a[j];
            j++;
        }
    }
    if(i<=mid) for(;i<=mid;i++) temp[k++]=a[i];
    else if(j<=last) for(;j<=last;j++) temp[k++]=a[j];
    for(int i=0;i<k;i++){
        a[i+first]=temp[i];
    }
}
void mergesort(long long a[],int first,int last){
    if(first<last){
        int mid=(last+first)/2;
        mergesort(a,first,mid);
        mergesort(a,mid+1,last);
        merge(a,first,mid,last);
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
