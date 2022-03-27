#include <bits/stdc++.h>
using namespace std;
typedef struct  jj
{
    int a;
    int c;
}jj;
bool cmp(jj a1,jj b1)
{
    return a1.c > b1.c;
}
int v[1000000];
int main()
{
    int n,m;
    cin>>n>>m;
    jj s[n];
    if(n<=m)
    {
        cout<<n;
        return 0;
    }
    int f[n];
    for(int i = 0; i < n; i++)
    {
        cin>>f[i];
    }
    sort(f,f+n);
    for(int i = 1; i < n; i++)
    {
        s[i-1].a = i;
        s[i-1].c = f[i] - f[i-1];
    }
    sort(s,s+n-1,cmp);
    for(int i = 0; i < m - 1; i++)
    {
        v[s[i].a] = 1;
    }
    int sum = 0;
    int xum = 0;
    for(int i = 1; i < n; i++)
    {
        if(!v[i])
        {
            xum+=f[i] - f[i-1];
        }
        else 
        {
            sum+=xum+1;
            xum = 0;
        }
    }
    sum+=xum+1;
    cout<<sum;
    system("pause");
    return 0;
}