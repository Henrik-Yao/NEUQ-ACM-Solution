#include<bits/stdc++.h>
using namespace std;
int t,n;
int num[10010];
int mmax[10010];
int main(){
    cin>>t;
    while(t--){
    	memset(mmax,0,10010);
        cin>>n;
        for(int i=1;i<=n;i++)
        cin>>num[i];
        for(int i=1;i<=n;i++){
           for(int j=1;j<i;j++){
               if(num[j]<num[i])
               mmax[i]=max(mmax[i],mmax[j]+1);
           }
          // cout<<mmax[i]<<endl;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,mmax[i]);
        }
        cout<<ans+1<<endl;//加一在于，初始的mmax=0，但实际每一个数最短就是他自己，也就是1的；
        if(t>=1) cout<<endl;
    }

    return 0;
}