#include<bits/stdc++.h>
using namespace std;

long long my_pow(long x,int n, int c)
{
    if(n==0)
    {
        return 1;
    }
    long long p=1;
    while(n>0)
    {
        if(n&1)//Å¼Êý                   
        {
            p = p * x % c;
        }
        x = (x % c) * (x % c) %c;
        n/=2;
    }
    return p % c;
}

int main() {
	int t;
	int a,b,c;
	cin >> t;
	while(t--){
		cin >> a >> b >> c;
		cout << my_pow(a%c, b, c) << endl;
	}	 
}
