#include<bits/stdc++.h>
using namespace std;

int n,m,q;
int father[1010];
int R[1010];
int t[1010];
//建立新集合
void make_set(int x)
{
    father[x]=x;   //根节点
    R[x]=0;      //秩的大小
}
//返回x所在集合的根节点
int find_set(int x)
{
    if(x!=father[x])
    {
        father[x]=find_set(father[x]);
    }
    return father[x];
}
//合成一个集合
void Union(int x,int y)
{
    int grandx=find_set(x);
    int grandy=find_set(y);

    if(grandx == grandy)
    {
        return ;
    }
    if(R[grandx]<R[grandy])
    {
        father[grandx] = grandy;
    }
    else
    {
        if(R[grandx]==R[grandy])
        {
            R[grandx]++;
        }
        father[grandy]=grandx;
    }
}

int main()
{

    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        make_set(i);
    }
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        Union(a,b);
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        if(find_set(x)==find_set(y))
        {
            cout<<"In the same gang."<<endl;
        }
        else
        {
            cout<<"In different gangs."<<endl;
        }
    }
    int temp;
    for(int i=1;i<=n;i++)
    {
        temp=find_set(i);
        t[temp]=1;
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum=sum+t[i];
    }
    cout<<sum;
}

