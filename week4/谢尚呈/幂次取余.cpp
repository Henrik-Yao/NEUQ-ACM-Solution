#include<iostream>
#include<cstdio>
using namespace std;

long long qpow(long long num, long long pow, long long mod)
{
    long long ans = 1; 
    while (pow)
    {
        if (pow&1)
            ans*=num;
        pow>>=1;
        num%=mod;
        num*=num;
        ans%=mod;
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int i=0; i<T; i++)
    {
    	int a, b, c;
    	scanf("%d %d %d", &a, &b, &c);
    	a%=c;
    	a=qpow(a, b, c);
    	printf("%d", a);
    	if(i!=T-1)	printf("\n");
	}
	return 0;
}
