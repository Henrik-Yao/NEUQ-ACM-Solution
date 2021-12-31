#include<iostream>
#include<stack>
using namespace std;
int nkt[100001],loft[100001],n;
int main()
{
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
                nkt[t]=z.top();
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
            while(t--) x=nkt[x];
        }
        else
        {
            t=loft[y]-loft[x];
            while(t--) y=nkt[y];
        }
        while(nkt[x]!=nkt[y])
        {
            x=nkt[x];
            y=nkt[y];
        }
        cout<<nkt[x]<<"\n";
    }
}
