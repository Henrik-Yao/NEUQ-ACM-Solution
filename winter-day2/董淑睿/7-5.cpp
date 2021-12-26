#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _=1e6+7;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
priority_queue<int,vector<int>,greater<int> > q;
map<char,int>p;
bool cmp(string a, string b){return a<b;}
int main() {
    int m,n,t;cin>>n;
    char c;
    for(int i=1;i<=n;i++)
        cin>>c>>t,p[c]=t,q.push(t);
    int ans=0;
    while(q.size()>1){
        int x=q.top();
        q.pop();
        int y=q.top();
        q.pop();
        q.push(x+y);
        ans+=x+y;
    }
    cin>>m;
    for(int i=1;i<=m;i++) {
        int sum=0;
        char a;
        string b[2333];
        bool flag=1;
        for(int j=1;j<=n;j++) {
            cin>>a>>b[j];
            sum+=p[a]*b[j].size();
        }
        if(sum!=ans) {
            cout<<"No\n",flag=0;
        } else {
            sort(b+1,b+n+1);
            for(int j=2;j<=n;j++){
                for(int k=1;k<j;k++)
                    if(b[k]==b[j].substr(0,b[k].size())) {cout<<"No\n";flag=0;break;}
                if(!flag) break;
            }   
        }
        if(flag) cout<<"Yes\n";
    }
    return 0;
}
