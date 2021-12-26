#include <bits/stdc++.h>
using  namespace  std;
struct gg{
    int date;
    int v;
};
gg a[1000];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 1; i <= n; i++)
    {
        a[i].date = i;
        a[i].v = 0;
    }
    int w = 1;
    int t = 0;
    while (t!=n)
    {
        int t1 = 1;
        if(t%2==0)
        {
            while (t1!=m||a[w].v)
            {
                if(!a[w].v)
                {
                    w--;
                    t1++;
                }
                else w--;
                if(w==0)w=n;
            }
            cout<<a[w].date<<" ";
            a[w].v = 1;
            while (a[w].v&&t!=n-1){
                w--;
                if(w==0)w=n;
            }
        }
        else
        {
            while (t1!=k||a[w].v)
            {
                if(!a[w].v)
                {
                    w++;
                    t1++;
                } else w++;
                if(w==n+1)w=1;
            }
            cout<<a[w].date<<" ";
            a[w].v = 1;
            while (a[w].v&&t!=n-1){
                w++;
                if(w==n+1)w=1;
            }
        }
        t++;
    }
    cout<<endl;
    return  0;
}