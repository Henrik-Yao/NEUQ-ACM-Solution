#include<iostream>
using namespace std;
int crime[1010];

int find(int x)
{
    return x==crime[x]?x:find(crime[x]);
}

void union_set(int x,int y)
{
    x = find(x);
    y = find(y);
    if(x!=y) crime[y] = crime[x];
}

int main()
{
        int n,m,q;
        int a,b;
        cin>>n>>m>>q;
        for(int i=1;i<=n;i++)
            crime[i] = i;
        for(int i=1;i<=m;i++){
            cin>>a>>b;
            union_set(a,b);
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            if(crime[x] == crime[y])
                cout<<"In the same gang."<<endl;
            else cout<<"In different gangs."<<endl;
        }
        int ans = 0;
        for(int i=1;i<=n;i++)
            if(crime[i] == i)//统计有多少个集合
                ans++;
        cout<<ans<<endl;//输出答案
    return 0;
}

