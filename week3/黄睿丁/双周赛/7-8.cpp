#include <iostream>
using namespace std;
int main()
{
	int n,m;
    cin>>n>>m;
    int a[n+1],i;
    for(i=1;i<=n;++i)
    cin>>a[i];
    if(m>a[n])
    cout<<n+1;
    else
    {
        for(i=1;i<=n;i++)
        {
            if(m<=a[i])
            {
                cout<<i;
            break;
            }
        }
    }
}

