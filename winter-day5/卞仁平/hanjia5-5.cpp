#include<bits/stdc++.h>
using namespace std;

map<string,pair<bool,string>>mp;

bool is(string a,string b)
{
    int i=1,j;
    for(string A=a;!A.empty();A=mp[A].second,i++)
    {
        j=1;
        for(string B=b;!B.empty();B=mp[B].second,j++)
        {
            if(i>=5 && j>=5) 
                return 1;
            if(A==B && (i<5 || j<5))
                return 0;
        }
    }
    return 1;
}

int main()
{
    cin.sync_with_stdio(false);
    int n,m;
    string str,a,b;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        if(b.back()=='n')
            mp[a]={1,b.substr(0,b.size()-4)};
        else if(b.back()=='r')
            mp[a]={0,b.substr(0,b.size()-7)};
        else if(b.back()=='m')
            mp[a]={1,""};
        else mp[a]={0,""};
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>str>>b>>str;
        if(mp.find(a)==mp.end() || mp.find(b)==mp.end())
            cout<<"NA\n";
        else if(mp[a].first==mp[b].first)
            cout<<"Whatever\n";
        else if(is(a,b)==1) cout<<"Yes\n";
        else cout<<"No\n";
    }

    return 0;
}