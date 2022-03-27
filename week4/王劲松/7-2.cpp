#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[50];
    memset(a,0,sizeof(a));
    a[1]=0,a[2]=1,a[3]=2;
    int i;
    for(i=4;i<=40;i++){
        a[i]=a[i-2]+a[i-1];
    }
    int n;
    cin>>n;
    while(n--){
        cin>>i;
        cout<<a[i]<<endl;
    }
    return 0;
}
