#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool flag[20001];
vector<int> rela[20001];
void dfs(int n)
{
    cout<<n<<" ";
    flag[n]=1;
    for(int i=0;i<rela[n].size();i++)
    {
        if(flag[rela[n][i]]==0) dfs(rela[n][i]);
    }
    return ;
}

int main()
{
    int n,e,x,y;
    cin>>n>>e;
    for(int i=1;i<=e;i++)
    {
        cin>>x>>y;
        rela[x].push_back(y);
    }
    for(int i=0;i<n;i++)
        sort(rela[i].begin(),rela[i].end());
    for(int i=0;i<n;i++)
    {
        if(flag[i]==0) dfs(i);
    }
    return 0;
}