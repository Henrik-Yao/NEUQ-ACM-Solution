#include<bits/stdc++.h>
using namespace std;
bool vst[10000001]={0};
long long prime[10000001],k=0;
int main(){
    long long n;
    cin>>n;
    for(int i=2;i<=n;i++){
         if(!vst[i]) prime[k++]=i;
         for(int j=0;i*prime[j]<=n;j++){
             vst[i*prime[j]]=1;
             if(i%prime[j]==0) break;
         }
     }//欧拉筛
    cout<<k<<endl;
    
    return 0;
}