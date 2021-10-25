#include<bits/stdc++.h>
using namespace std;

int main()
{
    int r,d,n;
    cin>>r>>d>>n;
    double x,s,sum;
    x=d*d+(abs(n)-r)*(abs(n)-r);
    s=pow(x,0.5);
    if(r<abs(n))
    {
      sum=s+s-r;
    }
    else
    {
        sum=2*abs(d)-r;
    }


    printf("%.2f",sum);
}
