#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int state[20010];
vector<int> edge[20010],answer;
void dfs(int i)
{
    state[i]=1;
    answer.push_back(i);
    for(int j=0;j<edge[i].size();j++)
    {
        if(state[edge[i][j]]==0)
            dfs(edge[i][j]);
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    int s,f,i;
    for(i=0;i<e;i++)
    {
        cin>>s>>f;
        edge[s].push_back(f);
    }
    for(i=0;i<n;i++)
    sort(edge[i].begin(),edge[i].end());
    for(i=0;i<n;i++)
    {
        if(state[i]==0)
        dfs(i);
    }
    for(i=0;i<answer.size();i++)
    {
        int a=answer[i];
        cout<<a<<" ";
    }
    
    
}
