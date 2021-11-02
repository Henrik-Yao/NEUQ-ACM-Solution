#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int main(){
    int n,j,i,cnt=0;
    cin>>n;
    memset(a,0,sizeof(a));
    for(i=2;i*i<=n;i++){
        if(!a[i]){
            for(j=i*i;j<=n;j+=i){
                a[j]=1;
            }
        }
    }
    for(i=2;i<=n;i++){
        if(a[i]==0)cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
