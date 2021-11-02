#include <bits/stdc++.h>
using namespace std;

vector<int> vv[10020];
int b[10020]={0};

int judge(int n)
{
    for(int i=1; i<=n; i++)
    {
        if(b[i])
            continue;
        for(int j=0; j<vv[i].size(); j++)
            if(b[vv[i][j]]==0)
                return 0;
    }
    return 1;
}
int main(void)
{
    int n, m, u, v, np, jud, l_b;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>u>>v;
        vv[u].push_back(v);
    }
    l_b=sizeof(b);
    cin>>np;
    while(np--)
    {
        
        memset(b, 0, l_b);
        
        int nnp, a;
        cin>>nnp;
        for(int i=0; i<nnp; i++)
        {
            cin>>a;
            b[a]++;
        }
        jud=judge(n);
        if(jud)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<endl;
    }
    return 0;
}