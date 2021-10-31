#include <iostream>
using namespace std;
void fac(int a, long long*p)
{
    *p=*p+1;
    for(int i=1; 2*i<=a; i++)
        if(a%i==0)
            fac(i, p);
    return;
}
int main(void)
{
	int n;
    long long m=0;
    long long *p;
    p=&m;
    cin>>n;
    
    fac(n, p);
    cout<<m;
	
	return 0;
}