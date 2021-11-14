#include<bits/stdc++.h>
using namespace std;

bool su(int n)
{
    int i;
    for(i=2;i<n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int a,b;
    while(cin>>a,cin>>b)
    {
        int p=0;
        int i;
        for(i=a;i<=b;i++)
        {
            if(su(i))
            {
                if(p==1)
                {
                    cout<<" ";
                }
                cout<<i;
                p=1;
            }
        }
        cout<<endl;
    }
    return 0;
}
