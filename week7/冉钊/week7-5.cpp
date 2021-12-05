#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;  
ull n,c;
ull bag[410][1510],w[410],v[410];
ull ans;
int main(){
    while(cin>>n>>c){
        for(int i=1;i<=n;i++){
            cin>>w[i];
        }//重量
        for(int i=1;i<=n;i++){
            cin>>v[i];
        }//价值
        for(int i=1;i<=n;i++)
            for(int j=0;j<=c;j++){
                bag[i][j]=bag[i-1][j];
                if(j>=w[i])
                bag[i][j]=max(bag[i][j],bag[i-1][j-w[i]]+v[i]);//在容量为j的情况下，我们选择是否装入第i个物品，让容量最大；
            }
       ans=bag[n][c];
        cout<<ans<<endl;
    }
}