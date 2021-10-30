#include <bits/stdc++.h>
using namespace std;
int n1,n2,a[101],b[101],c[101];
int merge(int a[],int b[]){
    int i=0,j=0,k=0;
    while(i<n1&&j<n2){
        if(a[i]<b[j]){
            c[k++]=a[i++];
        }
        else c[k++]=b[j++];
    }
    while(i<n1) c[k++]=a[i++];
    while(j<n2) c[k++]=b[j++];
    return k;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n1;
        for(int i=0;i<n1;i++){
            cin>>a[i];
        }
        cin>>n2;
        for(int i=0;i<n2;i++){
            cin>>b[i];
        }
        int len=merge(a,b);
        for(int i=0;i<len-1;i++){
            cout<<c[i]<<' ';
        }
        cout<<c[len-1]<<endl;
    }
    return 0;
}
