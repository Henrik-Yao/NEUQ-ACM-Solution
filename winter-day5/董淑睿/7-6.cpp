#include <bits/stdc++.h>
using namespace std;
const int _=2e5+7;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}

int main(){
    int n;
    while(cin>>n) {
        vector<int> a;
        for(int i=1;i<=n;++i) {
            int tmp=read();
            a.push_back(tmp);
        }
        sort(a.begin(),a.end());
        int m=read();
        for(int i=0;i<n;++i) {
            cout<<a[i];
            if(i!=n-1) cout<<" ";
        } cout<<"\n";
//         cout<<"\n";
        for(int i=1;i<=m;++i) {
            int val=read();
            // cout<<val<<"!!\n";
            vector<int>::iterator t=lower_bound(a.begin(),a.end(),val);
            if(t==a.end()) cout<<"0";
            else if(*t!=val) cout<<"0";
            else cout<<t-a.begin()+1;
            if(i==m)cout<<"\n";
            else cout<<" ";
        }
    }
    return 0;
} 