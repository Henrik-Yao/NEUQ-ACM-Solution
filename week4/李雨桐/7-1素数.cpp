#include <bits/stdc++.h>
using namespace std;

int prime(int a) //0表示是素数，1表示不是素数
{
    if(a==2)
        return 0;
    else
    {
        for(int i=2;i<=sqrt(a);i++)
        {
            if(a%i==0)
            return 1;
        }
        return 0;
    }
}

int main()
{
    int a,b;
    while(cin>>a,cin>>b)
    {
        int cnt=0;
        for(int i=a;i<=b;i++)
        {
            if(prime(i)==0 && cnt==0)
                {
                    cout<<i;
                    cnt=1;
                }
            else if(prime(i)==0 && cnt!=0)
                cout<<' '<<i;

        }
        cout<<endl;
    }

    return 0;
}
