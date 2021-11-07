#include<bits/stdc++.h>
using namespace std;
int a,b,k=0;
bool vst[100001]={0};
int prime[100001];
void oprime(){
     for(int i=2;i<10000;i++){
        if(!vst[i]) prime[k++]=i;
        for(int j=0;i*prime[j]<10000;j++){
            vst[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
     }
}//欧拉筛
int main(){
    int i=0,n;
    oprime();
    while(cin>>a>>b){
        i=0;
        while(prime[i]<a){
            i++;}
        while(prime[i]<=b&&prime[i]>=a){
            n=i;
         cout<<prime[i++];
         if(prime[++n]<=b) cout<<" ";//判断最后一位，让最后一位不输出空格；
        }
         cout<<endl;
    }
    
    return 0;
}