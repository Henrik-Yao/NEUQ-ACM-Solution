#include<bits/stdc++.h>
using namespace std;
map<char,int>mmp;
priority_queue<int,vector<int>,greater<int>>rua;
int main()
{
    int n,m,f,sum=0;
    char word;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>word>>f;
        mmp[word]=f;
        rua.push(f);
    }
    while(rua.size()!=1)
    {
        int x=rua.top();
        rua.pop();
        int y=rua.top();
        rua.pop();
        sum=sum+x+y;
        rua.push(x+y);
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int sss=0,flag=1;
        string str[64];
        for(int i=1;i<=n;i++)
        {
            cin>>word>>str[i];
            for(int j=1;j<i;j++)
            {
                int len=min(str[j].size(),str[i].size());
                if(str[i].substr(0,len)==str[j].substr(0,len))
                {
                    flag=0;
                    break;
                }
            }
            sss=sss+mmp[word]*str[i].size();
        }
        if(flag==1 && sss==sum) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}