#include <iostream>
#include <math.h>
using namespace std;

int main(){
    double r,d,n;
    cin>>r>>d>>n;
    d = abs(d);
    n = abs(n);
    r = abs(r);
    double sum;
    if(n==0||n-r<0)sum = 2*d - r;
    else if(d==0)sum = n - r;
    else {
        sum = 2*sqrt(d*d+(n-r)*(n-r))-r;
    }
    printf("%.2f",sum);
    return 0;
}