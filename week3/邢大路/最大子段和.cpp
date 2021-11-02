#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    int maxx=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    if(maxx==0){
        cout<<maxx<<endl;
        return 0;
    }
    else{
        int tmp=0,ans=0;
        for(int i=0;i<n;i++){
            tmp+=a[i];
            if(tmp<0)tmp=0;
            ans=max(ans,tmp);
        }
        cout<<ans<<endl;
    }
    return 0;
}
