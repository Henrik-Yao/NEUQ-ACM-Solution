#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int main()
{
    double R,d,n;
    cin>>R>>d>>n;
    n=fabs(n);
    if(n<=R)
        printf("%.2lf",2*d-R);
    else
        printf("%.2lf",2.0*sqrt(d*d+(n-R)*(n-R))-R);
    return 0;
}
