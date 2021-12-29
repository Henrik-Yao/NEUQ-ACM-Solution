#include<bits/stdc++.h>
using namespace std;
const int N=20009;
int n,m,t;
vector<int> v[N];
map<pair<int,int>,int >mm;
int siz[N];
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        v[a].push_back(b);
        siz[a]++;
        mm[{a,b}]=c;
    }
    cin>>t;
    while(t--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        for(int i=0;i<v[a].size();i++)
        {
            if(v[a][i]==b)
            {
                v[a][i]=-1;
                siz[a]--;
                break;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        sort(v[i].begin(),v[i].end());
    }
    for(int i=0;i<n;i++)
    {
        if(siz[i]!=0)
        {
            printf("%d:",i);
            for(int j=0;j<v[i].size();j++)
            {
                if(v[i][j]!=-1)
                printf("(%d,%d,%d)",i,v[i][j],mm[{i,v[i][j]}]);
            }
            cout<<endl;
        }
    }
    return 0;   
}

