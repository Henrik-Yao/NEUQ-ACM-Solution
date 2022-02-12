#include<bits/stdc++.h>
using namespace std;
#define N 20000

int main() {
    int n,e;
    cin>>n>>e;
    map <int ,map<int ,int>> num;
    for(int i = 0; i < e; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        num[a][b] = c;
    }
    int k;
    cin>>k;
    for(int i = 0; i < k; i++)
    {
        int a,b;
        cin>>a>>b;
        num[a].erase(b);
    }
    for(auto i:num)
    {
        if(i.second.empty())continue;
        cout<<i.first<<":";
        for(auto j:i.second)
        {
            printf("(%d,%d,%d)",i.first,j.first,j.second);
        }
        cout<<endl;
    }
    return 0;
}