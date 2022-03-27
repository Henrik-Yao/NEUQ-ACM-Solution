#include <bits/stdc++.h>
using namespace std;
void Adjust_heap(int a[],int parent,int n){
    int child=2*parent+1;
    while(child<n){
        if(child+1<n&&a[child]<a[child+1])
            child++;
        if(a[child]>a[parent])
            swap(a[child],a[parent]);
        parent=child;
        child=2*child+1;
    }
}
void HeapSort(int a[],int n){
    for(int i=n/2-1;i>=0;i--){
        Adjust_heap(a,i,n);
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=n-1;i>0;i--){
        swap(a[i],a[0]);
        Adjust_heap(a,0,i);
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
            cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    int arr[1001];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    HeapSort(arr,n);
    return 0;
}
