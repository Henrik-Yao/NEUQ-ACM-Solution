#include<bits/stdc++.h>
using namespace std;
const int k=100000+5;
string name[k];
int fa[k],fe[k],st[k];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>fa[i]>>name[i];
    for(int j=1;j<=m;j++)
        cin>>fe[j]>>st[j];
    int k=1;
    for(int i=1;i<=n;i++){
        if(fa[k]==fe[i])
            k=(k+n-st[i])%n;
        else
            k=(k+st[i])%n;
    }
    cout<<name[k];
    return 0;
}
