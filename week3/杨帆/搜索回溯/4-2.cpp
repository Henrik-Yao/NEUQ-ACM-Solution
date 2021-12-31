#include<bits/stdc++.h>
using namespace std;
const int k=500+5;
int to[k * k],he[k],ne[k * k],st,flag;
int s,d;
void add(int a,int b){
    to[st]=b;
    ne[st]=he[a];
    he[a]=st++;
}

int num[k];
int dfs(int x){
    int sum = 0;
    if(num[x] != -1)  return num[x];
    if(x == d)    return num[x]=1;
    if(he[x]==-1){
        flag=1;
        return num[x] = 0;
    }
    for(int i = he[x]; i != -1; i = ne[i]){
        int dx = to[i];
        sum += dfs(dx); 
    }
    return num[x] = sum;
}

int main(){
    int n,m;
    cin >> n >> m;
    memset(num,-1,sizeof(num));
    memset(he,-1,sizeof(he));
    for(int i=1;i<=m;++i){
        int a,b;
        cin>>a>>b;
        add(a,b);
    }
    int ans=0;
    cin>>s>>d;
    ans=dfs(s);
    cout<<ans<<" ";
    if(flag||!ans)  cout<<"No";
    else    cout<<"Yes";
    return 0;
}
