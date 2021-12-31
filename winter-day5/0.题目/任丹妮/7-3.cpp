#include <bits/stdc++.h>
using namespace std;
    int n,a[1000101],b[1000101],temp[1000101*2];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int i=0,j=0,k=0;
    while(i<n&&j<n){
        if(a[i]<b[j]) temp[k++]=a[i++];
        else temp[k++]=b[j++];
    }
    while(i<n){
        temp[k++]=a[i++];
    }
    while(j<n){
        temp[k++]=b[j++];
    }
    cout<<temp[(k-1)/2]<<endl;
}
