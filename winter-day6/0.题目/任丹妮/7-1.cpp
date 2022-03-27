#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        int a[1001];
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(n==1) cout<<a[0]<<endl;
    else {
        for(int i=1;i<n;i++){
        int t=a[i];
        int j;
        for(j=i-1;j>=0&&a[j]>t;j--){
            a[j+1]=a[j];
        }
        a[j+1]=t;
        for(int j=0;j<n-1;j++)
            cout<<a[j]<<" ";
        cout<<a[n-1]<<endl;
    }
    }
    }
    return 0;
}
