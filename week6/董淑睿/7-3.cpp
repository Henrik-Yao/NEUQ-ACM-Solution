#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _=2e6+7;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
unsigned int has[_],po[_];
unsigned int get_hash(int l,int r) {
    return has[r]-po[r-l+1]*has[l-1];
}
string a[10000];
bool pd(char s) {
    if(s>='a'&&s<='z') return 1;
    if(s>='A'&&s<='Z') return 1;
    return 0;
}
int main() {
    int n=1;
    char s;
    while(s=getchar()) {
        if(s=='\n') break;
        if(pd(s)) a[n]+=s;
        else if(a[n].length()!=0) n++;
    }
    cin>>a[++n];
    for(int i=1;i<=n;++i) {
        for(int j=0;j<(int)a[i].length();++j)
            if(a[i][j]>='A'&&a[i][j]<='Z') a[i][j]=a[i][j]-'A'+'a';
    }
    po[0]=1;
    for(int i=1;i<=10000;++i) po[i]=po[i-1]*233;
    unsigned int find_=0;
    for(int i=0;i<(int)a[n].length();++i) find_=find_*233+a[n][i];
    int ans=0;
    for(int j=1;j<n;++j) {
        for(int i=1;i<=(int)a[j].length();++i) {
            has[i]=has[i-1]*233+a[j][i-1];
            if(i>=a[n].length()&&get_hash(i-a[n].length()+1,i)==find_) {
                ans++;
                break;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
