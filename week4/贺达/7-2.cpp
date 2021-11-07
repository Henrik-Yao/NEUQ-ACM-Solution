#include<bits/stdc++.h>
using namespace std;

int louti(int n)
{
    if(n==1)
    {
        return 0;
    }
    else if(n==2)
    {
        return 1;
    }
    else if(n==3)
    {
        return 2;
    }
    else
    {
        return louti(n-2)+louti(n-1);
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int m;
        cin>>m;
        cout<<louti(m);
        if(i!=n)
        {
            cout<<endl;
        }
    }
    return 0;
}
