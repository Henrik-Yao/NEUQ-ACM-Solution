#include<bits/stdc++.h>
using namespace std;
struct node
{
    char sex;
    int fath;
    int mom;
}p[100009];
int n,m;
bool ishav[100009];
int self,fa,mo;
char gen;
bool flag=0;
char sex[100009];
map<int,int> mm;
void dfs(int gen,int id)
{
    if(gen==6) return ;
    if(mm[id])
    {
        flag=1;
        return ;
    }
    if(flag) return ;
    mm[id]=1;
    if(!ishav[id]) return ;
    if(p[id].fath!=-1)
    dfs(gen+1,p[id].fath);
    if(p[id].mom!=-1)
    dfs(gen+1,p[id].mom);
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>self>>gen>>fa>>mo;
        ishav[self]=1;
        p[self]={gen,fa,mo};
        sex[self]=gen;
        if(fa!=-1)
        sex[fa]='M';
        if(mo!=-1)
        sex[mo]='F';
    }
    cin>>m;
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        flag=0;
        if(sex[a]==sex[b])
        cout<<"Never Mind"<<endl;
        else 
        {
            mm.clear();
            dfs(1,a);
            dfs(1,b);
            if(flag) cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }
    }
    return 0;
}
