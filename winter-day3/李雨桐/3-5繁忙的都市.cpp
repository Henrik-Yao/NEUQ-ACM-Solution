#include<bits/stdc++.h>
using namespace std;

struct dushi
{
    int u;
    int v;
    int d;
};

int n,m,maxi,far[505];
dushi a[90005];

int searc(const dushi &x,const dushi &y)
{
    if (x.d<y.d)
        return 1;
    else
        return 0;
}
int findfar(int x)
{
    if (far[x]!=x)
        x=findfar(far[x]);
    return
        far[x];
}
void gener(int x,int y)
{
    int p=findfar(x),q=findfar(y);
    if (p!=q)
        far[p]=q;
}

int main()
{
    cin>>n>>m;

    for (int i=1;i<=m;i++)
        cin>>a[i].u>>a[i].v>>a[i].d;
    for (int i=1;i<=n;i++)
        far[i]=i;

    cout<<n-1<<' ';
    sort(a+1,a+m+1,searc);

    int temp=0;
    for (int i=1;i<=m;i++)
        {
            if (findfar(a[i].u)!=findfar(a[i].v))
                {
                    gener(a[i].u,a[i].v);
                    temp++;
                    maxi=max(maxi,a[i].d);
                }

            if (temp==n-1)
                break;
        }

    cout<<maxi;
    return 0;
}
