#include <bits/stdc++.h>
using namespace std;
int main(){
    long long a[36];
    int n;
    a[1]=2;
    while(cin>>n){
        for(int i=2;i<=n;i++){
            a[i]=2+3*a[i-1];
        }
        cout<<a[n]<<endl;
    }
    return 0;
}
