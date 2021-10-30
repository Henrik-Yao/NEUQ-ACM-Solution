#include <iostream>
#include <cmath>
using namespace std;
int main(void)
{
	double r, d, n, s;
    cin>>r>>d>>n;
    
    if(abs(n)>r)
        s=2*sqrt(d*d+(abs(n)-r)*(abs(n)-r))-r;
    else
        s=abs(2*d)-r;
    
    printf("%.2lf", s);
	
	return 0;
}