#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n, i, s, max;
    cin>>n>>max;
    
    s=max;
    while(n--)
    {
        cin>>i;
        s=s>0?s:0;
        s+=i;
        max=max>s?max:s;
    }
    if(max<0)
        max=0;
    
    cout<<max;
    
	return 0;
}