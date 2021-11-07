#include <bits/stdc++.h>
using namespace std;

int a[10000005];
int main()
{
    int n,m;
    cin>>n>>m;

    int i;
    for( i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>=m)
        {
            cout<<i;
            break;
        }
    }

    if(i>n)
        cout<<(n+1);

	return 0;
}
