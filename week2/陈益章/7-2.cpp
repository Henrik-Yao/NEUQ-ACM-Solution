#include <iostream>
#include<cstring>
#include<vector>
using namespace std;
vector<int>e[10010];
bool book[10010];
bool b(int j)
{
    for(int i=0; i<e[j].size(); i++)
        if(book[e[j][i]]==0)
            return 0;
    return 1;
}
int main()
{
    int n,m,np,x,y;
    cin>>n>>m;
    for (int o=0;o<m;o++)
    {
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    cin>>np;
    for (int o=0;o<np;o++)
    {
        int i;
        memset(book,0,sizeof(book));
        int k;
        cin>>k;
        while(k--)
        {
            int z;
            cin>>z;
            book[z]=1;
        }
        for(i=1; i<=n; i++)
            if(book[i]==0&&!b(i))
            {
                cout<<"NO"<<endl;
                break;
            }
       
        if(i==n+1)
            cout<<"YES"<<endl;
}
}