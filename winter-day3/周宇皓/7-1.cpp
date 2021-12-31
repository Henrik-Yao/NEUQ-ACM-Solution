#include<bits/stdc++.h>
using namespace std;
const int N=20009;
int n,m;
vector<int> v[N];
map<pair<int,int>,int >mm;
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        v[a].push_back(b);
        mm[{a,b}]=c;
    }
    for(int i=0;i<n;i++)
    {
        sort(v[i].begin(),v[i].end());
    }
    for(int i=0;i<n;i++)
    {
        if(v[i].size()!=0)
        {
            printf("%d:",i);
            for(int j=0;j<v[i].size();j++)
            {
                printf("(%d,%d,%d)",i,v[i][j],mm[{i,v[i][j]}]);
            }
            cout<<endl;
        }
    }
    return 0;   
}

