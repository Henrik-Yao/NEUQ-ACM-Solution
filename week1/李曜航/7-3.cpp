#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
int main()
{

    double r = read(), d = read(), n = read();
    n = fabs(n);
    d = fabs(d);
    if(r>=n)  printf("%.2lf",d*2-r);
    else {double dis1 = sqrt((n-r)*(n-r)+d*d);printf("%.2lf",dis1*2-r);}
    return 0;
}