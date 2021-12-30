#include <bits/stdc++.h>
using namespace std;
const int _=1e5+7;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
int n;
void A(vector<int>&a,int s,int m){
    int x=a[s];
    for(int i=s*2;i<=m;i*=2){
        if(i<m&&a[i]<a[i+1])i++;
        if(x>=a[i]) break;
        a[s]=a[i];s=i;
    } a[s]=x;
}
void C(vector<int>&a){
    for(int i=n/2;i>0;i--) A(a,i,n);
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    for(int i=n;i>1;i--){
        swap(a[1],a[i]);
        A(a,1,i-1);
        for(int i=1;i<=n;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
    }    
}
int main(){
    vector<int>a;
    n=read();
    a.resize(n+1);
    for(int i=1;i<=n;i++) a[i]=read();
    C(a);
    return 0;
}