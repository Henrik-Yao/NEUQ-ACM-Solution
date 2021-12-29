#include <bits/stdc++.h>
using namespace std;
int n;
void print(int *a){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
void Quick_sort(int *a,int low,int high){
    if(low>=high) return;
    int l=low;
    int r=high;
    int key=a[low];
    while(l<r){
        while(l<r&&a[r]>key){
            r--;
        }
        while(l<r&&a[l]<=key){
            l++;
        }
        swap(a[l],a[r]);
    }
    swap(a[l],a[low]);
    print(a);
    Quick_sort(a,low,l-1);
    Quick_sort(a,l+1,high);
}
int main(){
    cin>>n;
    int a[1001];
    for(int i=0;i<n;i++)
        cin>>a[i];
    Quick_sort(a,0,n-1);
    print(a);
}
