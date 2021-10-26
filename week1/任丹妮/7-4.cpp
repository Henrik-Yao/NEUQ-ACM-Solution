#include <iostream>
#include <cmath>
using namespace std;
int sushu(int n)
{
    int i;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0) break;
    }
    if(i>sqrt(n)) return 1;
    else return 0;
}
    int a[1001];
int cnt(int n)
{
    int sum=0;
    for(int i=1;i<=n/2;i++)
    {
        if(n%i==0) sum+=a[i];
    }
    return sum;
}
int main()
{
    int n;
    cin>>n;
    a[0]=1;
    a[1]=1;
    a[2]=2;
    for(int i=3;i<=n;i++)
    {
        if(sushu(i)) a[i]=2;
        else a[i]=cnt(i)+1;
    }
    cout<<a[n];
    return 0;
}
