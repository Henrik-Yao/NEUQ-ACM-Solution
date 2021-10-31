#include <bits/stdc++.h>
using namespace std;

vector <int >p[510];
bool flag[510];
int n,m;
int aim[510];

int dfs(int q)
{
    flag[q]=1;
    if(aim[q]) return aim[q];
        for(auto y:p[q])
        {
            aim[q]+=dfs(y);
        }
    return aim[q];
    
}

int main()
{
   cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int temp1,temp2;
        cin>>temp1>>temp2;
        p[temp1].push_back(temp2);
    }
    int s,t;
    cin>>s>>t;
    aim[t]=1;
    cout<<dfs(s)<<" ";
    int flag3=1;
    for(int i=1;i<=n;i++){
        if(!aim[i]&&flag[i]) flag3=0;
    }
    if(flag3) puts("Yes");
    else puts("No");
    return 0;
}
