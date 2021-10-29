#include<bits/stdc++.h>
using namespace std;
struct P{
    int flag;
    string name;
};
int main(){
  int n,m;
    cin>>n>>m;
    struct P a[100001];
    for(int i=1;i<=n;i++){
        cin>>a[i].flag>>a[i].name;
    }
    int num=1;
    for(int i=1;i<=m;i++){
        int c,b;
        cin>>b>>c;
        if(b==a[num].flag)num=num-c;
        else num=num+c;
        if(num<=0)num=n+num;
        else if(num>n)num=num-n;
    }
    
    cout<<a[num].name;
    return 0;
}
