#include<bits/stdc++.h>
using namespace std;
	int isprime[10000001],prime[10000001],tot = 0;

int getprime(int siz){
   for(int i=2;i<=siz;i++){
       if(!isprime[i])prime[++tot]=i;
       for(int j=1;j<=tot&&i*prime[j]<=siz;j++){
           isprime[i*prime[j]]=1;
           if(i%prime[j]==0)break;
       }
   }
   return tot;
}

int main(){
int n;
cin>>n;
   
    cout<<getprime(n)<<endl;
}

