#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[500];
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        x=x+100;
        a[x]++;
    }
    for(int i=0;i<=155;i++){
        if(a[i]==0)continue;
        else printf("%d:%d\n",i-100,a[i]);
    }
    return 0;
    
}
