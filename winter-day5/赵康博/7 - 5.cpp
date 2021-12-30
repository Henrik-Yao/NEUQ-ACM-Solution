#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int sex;
    string s;
}node;
map <string ,node> f;
int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        string a,b;
        cin>>a>>b;
        if(b.back() == 'f')f[a].sex = 0;
        else if(b.back() == 'm')f[a].sex = 1;
        else if(b.back() == 'n')f[a] = {1,b.substr(0,b.size() - 4)};
        else f[a] = {0,b.substr(0,b.size() - 7)};
    }
    int m;
    cin>>m;
    for(int i = 0; i < m; i++)
    {
        string a,b,c,d;
        cin>>a>>b>>c>>d;
        if(f.find(a) == f.end() || f.find(c) == f.end())cout<<"NA"<<endl;
        else if(f[a].sex == f[c].sex) cout<<"Whatever"<<endl;
        else {
            int t = 0;
            set<string > num,num2;
            for(int j = 0; j < 4&&!a.empty() ; j++){
                num.insert(a);
                a = f[a].s;
            }
            while (!a.empty())
            {
                num2.insert(a);
                a = f[a].s;
            }
            for(int j = 0; j < 4 && !c.empty(); j++)
            {
                if(num.find(c)!=num.end()|| num2.find(c)!=num2.end())
                {
                    t=1;
                    break;
                }
                c = f[c].s;
            }
            while (!c.empty()&&!t)
            {
                if(num.find(c)!=num.end())
                {
                    t = 1;
                    break;
                }
                c = f[c].s;
            }
            if(t == 0)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}
