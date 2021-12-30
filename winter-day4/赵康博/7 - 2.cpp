#include<bits/stdc++.h>
using namespace std;
#define N 1000
vector<int> f[N];
int v[N];
int fim(int x,int y)
{
    if(x==y)return 0;
    int min = 10000;
    v[x] = 1;
    for(auto it: f[x])
    {
        if(!v[it]){
            int num = fim(it,y);
            if(num<min)min = num;
        }
    }
    v[x] = 0;
    return min+1;
}
int main() {
    int n,m;
    while (cin>>n>>m)
    {
        for(int i = 0; i < n; i++){
            v[i] = 0;
            f[i].clear();
        }
        for(int i = 0; i < n; i++)
        {
            int a,b;
            int c;
            cin>>a>>b;
            for(int j = 0; j < b; j++)
            {
                cin>>c;
                f[a].push_back(c);
            }
        }
        for(int i = 0; i < m; i++)
        {
            int a,b;
            cin>>a>>b;
            int min = fim(a,b);
            if(min<10000)cout<<min<<endl;
            else cout<<"connection impossible"<<endl;
        }
    }
    return 0;
}