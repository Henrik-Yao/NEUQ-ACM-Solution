#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL powMod(LL a,LL b,LL c)
{
    LL result = 1;
    while(b)
    {
        if(b % 2 == 1)
            result = result * a % c;
        b /= 2;
        a = a * a % c;
    }
    return result;
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        LL a,n,p;
        cin>>a>>n>>p;
        cout<<powMod(a,n,p)<<endl;
    }


    return 0;
}
