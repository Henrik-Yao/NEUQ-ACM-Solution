#include <bits/stdc++.h>
using namespace std;
#define m 200006
int fu[m],mu[m];
char sex[m];
bool f;
bool is[m];
void dfs(int z,int gen)
{
    if(gen>5||z==-1||z==0)
    return ;
    if(is[z])
    f=1;
    is[z]=1;
    dfs(fu[z],gen+1);
    dfs(mu[z],gen+1);
    return ;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int ren;
        cin>>ren;
        cin>>sex[ren]>>fu[ren]>>mu[ren];
        sex[fu[ren]]='M';
        sex[mu[ren]]='F';
    }
    
    int k;
    cin>>k;
    int nan,nv;
    while(k--)
    {
        memset(is,0,sizeof(is));
        cin>>nan>>nv;
        if(sex[nan]==sex[nv])
        {
            cout<<"Never Mind\n";
            continue;
        }
        f=0;
        dfs(nan,1);
        dfs(nv,1);
        if(f==0)
        cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;

}