#include <bits/stdc++.h>
using namespace std;

vector<int > city[110];
bool temp1[110],temp2[110];

void dfs(int x)
{
    temp1[x]=1;
    for(auto y:city[x])
    {
        if(temp1[y]||!temp2[y]) continue;
        dfs(y);
    }
}

int main()
{
    int n,m,k,temp3;
    cin>>m>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>temp3;
        temp2[temp3]=true;
    }
    for(int j=0;j<k;j++)
    {
        int tempx,tempy;
        cin>>tempx>>tempy;
        city[tempx].push_back(tempy);
        city[tempy].push_back(tempx);
    }
    int from,to;
    cin>>from>>to;
    if(!temp2[to]){
        cout<<"The city "<<to<<" is not safe!";
        return 0;
    }
    dfs(from);
    if(temp1[to]) cout<<"The city "<<to<<" can arrive safely!";
    else cout<<"The city "<<to<<" can not arrive safely!";
    return 0;
    
}
