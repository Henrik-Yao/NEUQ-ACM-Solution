#include<bits/stdc++.h>
using namespace std;

struct dic{
    string e;
    string n;

};

dic a[10005];

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i].e>>a[i].n;
    }

    while(m--)
    {
        string t;
        cin>>t;

        int flag = 0;
        for(int i=1;i<=n;i++)
        {
            if(a[i].n == t)
            {
                cout<<a[i].e<<endl;
                flag = 1;
                break;
            }
        }

        if(flag==0)
            cout<<"eh"<<endl;
    }


    return 0;
}
