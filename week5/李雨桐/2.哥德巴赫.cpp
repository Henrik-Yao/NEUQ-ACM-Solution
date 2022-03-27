#include <bits/stdc++.h>
using namespace std;

int exam(int x)
{
    int flag1=1,flag2=1;
    if(x==2)
        return 1;
    if(x%2==0 && x!=2)
        return 2;

    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
        {
            flag1=0; break;
        }
    }

    if(flag1==1)
        return 1;
    else
    {
        for(int i=2;i<=sqrt(x-2);i++)
        {
            if((x-2)%i==0)
            {
                flag2=0; break;
            }
        }

        if(flag2==1)
            return 2;
        else
            return 3;
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;

        cout<<exam(x)<<endl;
    }

    return 0;
}
