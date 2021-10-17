#include<bits/stdc++.h>
using namespace std;
int ans[1005];
bool isprime(int x){
    if(x==2)    return true;
    else if(x%2==0) return false;
    else
        for(int i=3;i<=sqrt(x);i+=2)
            if(x%i==0)
                return false;
    return true;
}
int main(){
    int n;
    cin>>n;
    ans[1]=1,ans[0]=1;
    for(int i=2;i<=n;i++){
        if(isprime(i))
            ans[i]=2;
        else{
            for(int j=1;j<i;j++){
                if(i%j==0)
                    ans[i]+=ans[j];
            }
            ans[i]++;
        }
    }
    cout<<ans[n];
    return 0;
}
