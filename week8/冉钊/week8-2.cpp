#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
int main(){
    cin>>n;
    int road[n];
    for(int i=0;i<n;i++)
    cin>>road[i];
    //goal=从0到n-1
    //结束条件是i+road【i】》=n；
    for(int i=0;i<n;i++){
        if(i+road[i]>=n-1){ans++; break;}
        else {
            int flag=i+1;
            for(int j=i+2;j<=i+road[i];j++){
                if(flag+road[flag]<j+road[j]){
                    flag=j;
                    }//
            }
            ans++;
            i=flag-1;
        }
    }

    cout<<ans;
    return 0;
}