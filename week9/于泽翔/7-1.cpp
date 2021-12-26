#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	unsigned long long a[55]={1, 2, 4};
    int n;
	for(int i=3; i<50; i++)
		a[i]=a[i-1]+a[i-2]+a[i-3];
	while(cin>>n)
        cout<<a[n-1]<<endl;
	
	return 0;
}