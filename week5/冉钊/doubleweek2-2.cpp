#include<bits/stdc++.h>
using namespace std;
long long n,num,ans;
bool ifprime(long long num){
        if(num==2||num==3) return 1;
        if(num%6!=1&&num%6!=5) return 0;
        long long temp=sqrt(num);
        for(int i=5;i<=sqrt(num);i+=6)
           if(num%i==0||num%(i+2)==0) return 0;

        return 1;
}//判断素数函数
void prime(long long num){
         if(num%2==0){
             ans=2;return;
         }
         else{
            if(ifprime(num)){
                ans=1;return;
            }
            else if(ifprime(num-2)){
                ans=2;return;
            }
            else{
                ans=3;return;
            }
         }
}
int main(){
    cin>>n;
    while(n--){
      cin>>num;
      prime(num);
      cout<<ans;
      cout<<endl;
    }
    return 0;
}
