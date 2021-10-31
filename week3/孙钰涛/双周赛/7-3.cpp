#include<iostream>
using namespace std;
int main()
{
    long long x,res;
    while(cin>>x)
    {
        res=1;
        for(int i=1;i<=x;i++) res=res*3;
        cout<<res-1<<endl;
    }
    return 0;
}
