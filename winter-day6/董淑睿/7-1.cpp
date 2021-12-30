#include <bits/stdc++.h>
using namespace std;
const int _=1e3+7;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
int n;
int main(){
    while(cin>>n){
        vector<int> a;
        for(int i=0;i<n;++i) {
            int tmp=read();
            a.push_back(tmp);
        }
        for(int i=1;i<n;++i) {
            int j,m=a[i];
            for(j=i-1;j>=0&&a[j]>m;j--) a[j+1]=a[j];
            a[j+1]=m;
            for(int i=0;i<(int)a.size()-1;i++)
                printf("%d ",a[i]);
            printf("%d\n",a[a.size()-1]);
        }
        a.clear();
    }
    return 0;
}