#include <bits/stdc++.h>
using namespace std;

set<int>s[1001];
int cnt = 0;
int n,m,q;
int main(){
    cin>>n>>m>>q;
    for(int i = 0;i < m;i++){
        int a,b;
        cin>>a>>b;
        if(!s[cnt].count(a) && !s[cnt].count(b)){
        cnt++;
        s[cnt].insert(a);
        s[cnt].insert(b); 
        }
        else if(!s[cnt].count(a))
        s[cnt].insert(a);
        else if(!s[cnt].count(b))
        s[cnt].insert(b);
    }
    for(int i = 0;i < q;i++){
        int c,d;
        cin>>c>>d;
        bool flag = false;
        for(int i = 1;i <= cnt;i++){
            if(s[i].count(c) && s[i].count(d)){
                flag = true;
                break;
            }
        }
        if(flag)puts("In the same gang.");
        else puts("In different gangs.");
    }
    cout<<cnt<<endl;
    return 0;
}