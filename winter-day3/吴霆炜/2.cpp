#include <bits/stdc++.h>
using namespace std;

int n,e;
map<int,map<int,int> >m;
int main(){
    scanf("%d%d",&n,&e);
    for(int i = 0;i < e;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        m[a][b] = c;
    }
    int k;
    scanf("%d",&k);
    for(int i = 0;i < k;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        m[a].erase(b);
    }
    for(auto i:m){
        int x = i.first;
        string s = "";
        for(auto j:i.second){
            s += '(' + to_string(x) + ',' + to_string(j.first) + ',' + to_string(j.second) + ')';
        }
        if(s != "")
        cout<<x<<":"<<s<<endl;
    }
    return 0;
}