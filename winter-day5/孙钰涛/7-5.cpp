#include<bits/stdc++.h>
using namespace std;

map<string,pair<bool,string>>nmd;

bool judge(string a,string b)
{
    int i=1,j;
    for(string A=a;!A.empty();A=nmd[A].second,i++)
    {
        j=1;
        for(string B=b;!B.empty();B=nmd[B].second,j++)
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
            nmd[a]={1,b.substr(0,b.size()-4)};
        else if(b.back()=='r')
            nmd[a]={0,b.substr(0,b.size()-7)};
        else if(b.back()=='m')
            nmd[a]={1,""};
        else nmd[a]={0,""};
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>str>>b>>str;
        if(nmd.find(a)==nmd.end() || nmd.find(b)==nmd.end())
            cout<<"NA\n";
        else if(nmd[a].first==nmd[b].first)
            cout<<"Whatever\n";
        else if(judge(a,b)==1) cout<<"Yes\n";
        else cout<<"No\n";
    }

    return 0;
}