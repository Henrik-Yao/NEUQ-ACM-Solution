#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e,a,b,c;
    cin>>n>>e;
    map<int,map<int,int>> mp;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b>>c;
        mp[a][b]=c;
    }
    for(auto i:mp)
    {
        int a=i.first;
        string s="";
        for(auto j:i.second)
        {
            s+="("+to_string(a)+","+to_string(j.first)+","+to_string(j.second)+")";
        }
        cout<<a<<":"<<s<<endl;
    }
    return 0;
}