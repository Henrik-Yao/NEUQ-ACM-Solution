#include <bits/stdc++.h>
using namespace std;

long long hanoi(int n)
{
    if(n==1)
        return 2;
    else
        return 3*hanoi(n-1)+2;
}
int main(void)
{
	int n;
    while(cin>>n)
        cout<<hanoi(n)<<endl;
	
	return 0;
}