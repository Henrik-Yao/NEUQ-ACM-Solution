#include <bits/stdc++.h>
using namespace std;

vector <int> a[10005];
int b[10005];

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int t1,t2;
        cin>>t1>>t2;

        a[t1].push_back(t2);
    }

    int k;
    cin>>k;

    while(k--)
    {
        int np;
        cin>>np;

        memset(b,0,sizeof(b));

        while(np--)
        {
            int t;
            cin>>t;
            b[t] = 1;
        }

        int flag=1;

        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<a[i].size();j++)
            {
                if(b[i]!=1 && b[a[i][j]]!=1)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag==0)
                break;
        }

        if(flag==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
