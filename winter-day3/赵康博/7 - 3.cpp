#include<bits/stdc++.h>
using namespace std;
#define N 20
vector<int > f;
int n;
int v[N];
int sum = 0;
void dfs(int t)
{
    if(t>n)
    {
        if(f.size()>=2)sum++;
        return;
    }
    if(f.empty()||v[t] >= f.back())
    {
        f.push_back(v[t]);
        dfs(t+1);
        f.pop_back();
    }
    if(f.empty()||f.back()!=v[t])dfs(t+1);
}
int main() {
    cin>>n;
    for(int i = 1; i <= n; i++)cin>>v[i];
    dfs(1);
    cout<<sum;
    return 0;
}