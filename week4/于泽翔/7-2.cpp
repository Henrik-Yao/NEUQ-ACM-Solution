#include <bits/stdc++.h>
using namespace std;

long long f(int n)
{
	if(n<2)
		return 0;
	else if(n<5)
		return n-1;
	else
		return f(n-1)+f(n-2);
}
int main(void)
{
	int n, m;
    cin>>n;
	while(n--)
    {
        cin>>m;
        cout<<f(m)<<endl;
    }
	    
	
	return 0;
}