#include<bits/stdc++.h>
using namespace std;
bool isprime[10000005];
int n;
void F(){
    for(int i=2;i<=n;i++){
        if(isprime[i]){
            for(int j=2*i;j<=n;j+=i){
                isprime[j]=0;
            }
        }
    }
}
int main(){
    cin>>n;
    memset(isprime,1,sizeof(isprime));
    F();
    int count;
    for(int i=2;i<=n;i++){
        if(isprime[i])count++;
    }
    cout<<count<<endl;
    return 0;
}
