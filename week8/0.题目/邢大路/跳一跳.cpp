#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
   int a[n*2];
    int count=0;
    int now=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(now<n){
        if(now+a[now]>=n){
            count++;
            break;
        }
        int ans=0;
        int index=0;
        for(int i=1;i<=a[now];i++){
            if(a[now+i]+i>=ans)index=i;
            ans=max(ans,i+a[now+i]);
        }
        now=now+index;
        count++;
 
    }
    cout<<count;
}
