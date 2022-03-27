#include<iostream>
#include<cmath>
using namespace std;

bool judge(long long x)
{
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0) return 0;
    }
    return 1;
}

int main()
{
    long long x,n;
    cin>>n;
    for(int p=1;p<=n;p++)
    {
        cin>>x;
        if(x%2==0) cout<<2;
        else if(judge(x)==1) cout<<1;
        else if(judge(x-2)==1) cout<<2;
        else cout<<3;
        cout<<"\n";
    }
    return 0;
}