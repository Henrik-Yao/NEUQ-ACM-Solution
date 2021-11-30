#include<bits/stdc++.h>
using namespace std;
long long a[60];
long long f(int n)
{
    if(a[n]) return a[n];                                                   
    if(n==1) return 1;
    else if(n==2) return 2;
    else if(n==3) return 4;
    else return a[n]=f(n-1)+f(n-2)+f(n-3);
}
int main()
{
    int n;
    memset(a,0,sizeof(a));
    while(~scanf("%d",&n)) cout<<f(n)<<'\n';
    return 0;
}
