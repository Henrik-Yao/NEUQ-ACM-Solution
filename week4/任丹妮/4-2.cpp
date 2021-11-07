#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    long long f[41];
    cin>>n;
    f[0]=0;
    f[1]=1;
    f[2]=2;
    for(int i=3;i<=40;i++){
        f[i]=f[i-1]+f[i-2];
    }
    n=n-1;
    while(n--){
        cin>>m;
        cout<<f[m-1]<<endl;
    }
    cin>>m;
    cout<<f[m-1];
    return 0;
}
