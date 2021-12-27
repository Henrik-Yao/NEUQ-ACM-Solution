#include<bits/stdc++.h>
using namespace std;
int n,t;
map<char,int> m;
int main()
{
    cin>>n;
    char ch;
    int siz;
    for(int i=1;i<=n;i++)
    {
        getchar();
        scanf("%c %d",&ch,&siz);
        m[ch]=siz;
    }
    priority_queue<int,vector<int>,greater<int> > q;
    int sum=0;
    for(auto x:m) q.push(x.second);
    if(q.size()==1) sum=q.top();
    while(q.size()>1)
    {
        int a=q.top();
        q.pop();
        int b=q.top();
        q.pop();
        sum+=a+b;
        q.push(a+b);
    }
    cin>>t;
    while(t--)
    {
        char c;
        string str;
        set<string> s;
        bool flag=1;
        s.clear();
        int temp=0;
        vector<string> v;
        for(int i=1;i<=n;i++)
        {
            getchar();
            scanf("%c",&c);
            cin>>str;
            temp+=m[c]*str.size();
            int len=str.size();
            for(int i=0;i<v.size();i++)
            {
                if(v[i].substr(0,len)==str) flag=0;
            }
            v.push_back(str);
        }
        if(temp==sum&&flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
