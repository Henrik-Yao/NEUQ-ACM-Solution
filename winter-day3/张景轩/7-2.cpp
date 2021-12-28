#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,e,a,b,c,m;
    cin>>n>>e;
    map<int,map<int,int>> mp;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b>>c;
        mp[a][b]=c;
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        mp[a].erase(b);
    }
    for(auto i:mp)
    {
        int a=i.first;
        string s="";
        for(auto j:i.second)
        {
            s+="("+to_string(a)+","+to_string(j.first)+","+to_string(j.second)+")";
        }
        if(s!="")
        {
            cout<<a<<":"<<s<<endl;
        }
    }
    return 0;
}