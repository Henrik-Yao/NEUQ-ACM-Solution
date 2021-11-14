#include<bits/stdc++.h>
using namespace std;
int n;
bool st[100009];
int primes[10009],cnt;
int main()
{
    for(int i=2;i<=10000;i++)
    {
        if(!st[i]) primes[cnt++]=i;
        for(int j=0;primes[j]<=10000/i;j++)
        {
            st[primes[j]*i]=1;
            if(i%primes[j]==0) break;
        }
    }
    int a,b;
    while(cin>>a>>b)
    {
        bool flag=1;
        for(int i=a;i<=b;i++)
        {
            if(!st[i]) 
            {
                if(!flag) cout<<' ';
                if(flag) flag=0;
                cout<<i;
            }
        }
        cout<<endl;
    }
    return 0;
}
