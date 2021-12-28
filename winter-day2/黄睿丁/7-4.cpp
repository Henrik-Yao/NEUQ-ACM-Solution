#include <bits/stdc++.h>
using namespace std;
set<int>s[1001];
int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    int i,j,num=0;
    for(i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        j=0;
        if(!s[num].count(a) && !s[num].count(b))
        {
        num++;
        s[num].insert(a);
        s[num].insert(b); 
        }
        else if(!s[num].count(a))
        s[num].insert(a);
        else if(!s[num].count(b))
        s[num].insert(b);
    }
    for(i=0;i<q;i++)
    {
        int a,b,f=0;
        cin>>a>>b;
        for(j=1;j<=num;j++)
        {
            if(s[j].count(a)&&s[j].count(b))
            {
                f=1;
                break;
            }
        }
        if(f==0)
        {
            cout<<"In different gangs."<<endl;
        }
        else
        {
            cout<<"In the same gang."<<endl;
        }
    }
    cout<<num<<endl;
}
