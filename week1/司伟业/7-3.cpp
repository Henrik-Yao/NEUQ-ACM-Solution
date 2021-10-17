#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double r,d,n;
int main()
{
    cin>>r>>d>>n;
    d=abs(d);n=abs(n);
    if(n<=r)
    {
        printf("%.2lf",2*d-r);
        return 0;
    }
    n-=r;
    printf("%.2lf",2*sqrt(d*d+n*n)-r);
}
