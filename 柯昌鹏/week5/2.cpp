#include <bits/stdc++.h>
using namespace std;

bool judge(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
}

int main ()
{
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>m;
        if(m%2==0) {cout<<"2";continue;}
        if(judge(m)) {cout<<"1";continue;}
        if(judge(m-2)) {cout<<"2";continue;}
        puts("3");
    }
    return 0;
}