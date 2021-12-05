#include<bits/stdc++.h>
using namespace std;
#define M 10010

struct s
{
    string a;
    string b;
};

int main()
{
    s dian[M];
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        string x;
        string y;
        cin>>x>>y;
        dian[i].a=x;
        dian[i].b=y;
    }
    int p=0;
    for(int i=0;i<n;i++)
    {
        if(p!=0)
        {
            cout<<endl;
        }
        string z;
        cin>>z;
        int cnt=0;
        for(int j=0;j<m;j++)
        {
            if(z==dian[j].b)
            {
                cnt++;
                cout<<dian[j].a;
                p++;
            }
        }
        if(cnt==0)
        {
            cout<<"eh";
            p++;
        }
    }

    return 0;
}
