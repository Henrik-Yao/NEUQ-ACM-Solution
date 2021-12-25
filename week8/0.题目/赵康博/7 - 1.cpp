#include <bits/stdc++.h>
using namespace std;
typedef struct f{
    int start;
    int end;
}f;
bool tmp(f a,f b)
{
    if(a.start>b.start)return false;
    else if(a.start<b.start)return true;
    else {
        if(a.end>b.end)return false;
        else return true;
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        int m;
        cin>>m;
        f s[m];
        int max1 = 0;
        for(int j = 0; j < m; j++)
        {
            cin>>s[j].start>>s[j].end;
        }
        sort(s,s+m,tmp);
        int x[m];
        for(int j = 0; j < m; j++)
        {
            x[j] = 1;
        }
        for(int j = 1; j < m; j++)
        {
            for(int k = 0; k < j; k++)
            {
                if(s[j].start>=s[k].end)
                {
                    x[j] = max(x[j],x[k]+1);
                }
            }
            max1 = max(max1,x[j]);
        }
        cout<<m - max1<<endl;
    }
    return 0;
}