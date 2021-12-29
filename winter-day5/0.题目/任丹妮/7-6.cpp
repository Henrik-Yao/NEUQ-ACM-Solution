#include <bits/stdc++.h>
using namespace std;
int search(int *arr,int low,int high,int x){
    if(low>high) return -1;
    int mid=(low+high)/2;
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
    while(cin>>n){
        int a[1001];
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        for(int i=0;i<n-1;i++)
            cout<<a[i]<<" ";
        cout<<a[n-1]<<endl;
        int m;
        cin>>m;
        while(m--){
            int f;
            cin>>f;
            cout<<search(a,0,n-1,f)+1;
            if(m!=0) cout<<" ";
            else cout<<endl;
        }
    }
}
    
