#include<bits/stdc++.h>
using namespace std;
int father[100001],loft[100001],n;
int main()
{
    //father[i]表示i的父结点 loft[i]表示i的层数
    stack<int>z;
    int N;scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        int t;
        scanf("%d",&t);
        z.push(t);
        while (!z.empty())
        {
            scanf("%d",&t);
            if(t!=0)
            {
                father[t]=z.top();
                loft[t]=n++;
                z.push(t);
            }
            else
            {
                z.pop();
                n--;
            }
        }
        int x,y;
        scanf("%d",&x);
        scanf("%d%d",&x,&y);
        if(loft[x]>loft[y])
        {
            t=loft[x]-loft[y];
            while(t--) x=father[x];
        }
        else
        {
            t=loft[y]-loft[x];
            while(t--) y=father[y];
        }
        while(father[x]!=father[y])
        {
            x=father[x];
            y=father[y];
        }
        cout<<father[x]<<"\n";
    }
    return 0;
}