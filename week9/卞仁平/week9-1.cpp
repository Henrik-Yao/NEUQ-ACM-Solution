#include<bits/stdc++.h>
using namespace std;
long long a[55];
long long shu(int n)
{
    if(a[n])return a[n];
    if(n==1)return 1;
    else if(n==2)return 2;
    else if(n==3)return 4;
    else return a[n]=shu(n-1)+shu(n-2)+shu(n-3);
}
int main()
{
    int n;
    while(cin>>n)
    cout<<shu(n)<<"\n";
    //puts("%lld",shu(n));
    return 0;

}