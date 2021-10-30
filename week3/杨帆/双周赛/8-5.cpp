#include<bits/stdc++.h>
using namespace std;
int a[300];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;  cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int m;  cin>>m;
        for(int i=n+1;i<=m+n;i++){
            cin>>a[i];
        }
        sort(a+1,a+m+n+1);
        for(int i=1;i<n+m;i++)
            cout<<a[i]<<" ";
        cout<<a[n+m]<<endl;
    }
    return 0;
}
