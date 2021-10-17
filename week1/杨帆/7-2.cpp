#include<bits/stdc++.h>
using namespace std;
const int k=1e5+5,m=1e6+5;
int book[k],pre[m],suf[m],a[m];
int main(){
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++)
    		pre[i]=1;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        if(!book[a[i]])
            pre[i]+=pre[i-1];
        else
        		pre[i]=pre[i-1];
        book[a[i]]=1;
    }
    memset(book,0,sizeof(book));
    int max_=INT_MIN;
    suf[n]=1,book[a[n]]=1;
    for(int i = n-1;i > 0;i--){
        suf[i]=suf[i+1];
        if(!book[a[i]])
            suf[i]++;
        book[a[i]]=1;
        max_=max(max_,suf[i+1]+pre[i]);
    }
    cout<<max_;
    return 0;
}
