#include <bits/stdc++.h>
using namespace std;
int main()
//简化的快速幂
{
    int t;
    cin>>t;
    while (t--)
    {
        long long a,b,c;
        long long s=1;
        cin>>a>>b>>c;
        while(b>0)
        {
            if(b%2==1)
            s=s*a%c;

            b/=2;
            a=a*a%c;
        }
        cout<<s<<endl;
    }
}