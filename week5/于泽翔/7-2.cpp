#include <bits/stdc++.h>
using namespace std;

int isp(int a)
{
    for(int i=2; i*i<=a; i++)
        if(a%i==0)
            return 0;
    return 1;
}
int main(void)
{
	int n, m;
    cin>>n;
    while(n--)
    {
        cin>>m;
        
        if(m%2==0)
            cout<<2;
        else if(isp(m))
            cout<<1;
        else if(isp(m-2))
            cout<<2;
        else
            cout<<3;
        cout<<endl;
    }
	
	return 0;
}