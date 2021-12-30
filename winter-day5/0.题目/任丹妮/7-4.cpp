#include <bits/stdc++.h>
using namespace std;
int sum=0;
int search(int *arr,int low,int high,int x){
    if(low>high) return -1;
    int mid=(low+high)/2;
    sum++;
    if(arr[mid]==x)
        return mid;
    else if(arr[mid]<x){
        return search(arr,mid+1,high,x);
    }
    else {
        return search(arr,low,mid-1,x);
    }
}
int main(){
    int n;
    cin>>n;
        int a[1001];
        for(int i=0;i<n;i++)
            cin>>a[i];
            int f;
            cin>>f;
            cout<<search(a,0,n-1,f)<<endl;
    cout<<sum<<endl;
}
    
