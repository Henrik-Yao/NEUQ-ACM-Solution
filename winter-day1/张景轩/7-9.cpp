#include<iostream>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
using namespace std;
 
struct info
{
    string name;
    int t;
    int p;
}a[10000];

set<int> st[100];
map<int, int> mp; 
bool vis[10000] = {false};
queue<info> q;

int Hash(string s)
{
    return (s[0]-'A')*26*26 + (s[1]-'0')*26 + s[2]-'0';
}

int main()
{
    int n, m, l;
    string s;
    
    cin>>n>>m;
    for(int i=0; i<m; ++i)
    {
        cin>>l;
        while(l--)
        {
            cin>>s;
            st[i].insert(Hash(s));
            mp[Hash(s)] = i;
        }
    }

    for(int i=0;i<n;++i)
    {
       cin>>a[i].name>>a[i].t>>a[i].p;
        if(a[i].p > 60)
        {
            a[i].p = 60;
        }
    }
 
    q.push(a[0]);
    vis[0] = 1;
    int last = a[0].t + a[0].p;
    int sum = 0;
    while(!q.empty())
    {
        info f = q.front();
        q.pop();
        cout<<f.name<<endl;
        bool found = false;
        for(int i=1; i<n; ++i)
        {
            if(vis[i])
            {
                continue;
            }
            if(a[i].t > last)
            {
                break;
            }
            if(st[mp[Hash(f.name)]].count(Hash(a[i].name)))
            {
                q.push(a[i]);
                vis[i] = true;
                found = true;
                sum += last-a[i].t;
                last += a[i].p;
                break;
            }
        }
        if(!found)
        {
            for(int i=1; i<n; ++i)
            {
                if(vis[i])
                {
                    continue;
                }
                q.push(a[i]);
                vis[i] = true;
                sum += max(0, last-a[i].t);
                if(a[i].t > last)
                {
                    last = a[i].t;
                }
                last += a[i].p;
                break;
            }
        }
    }
    printf("%.1f\n", 1.0*sum/n);

    return 0;
}

