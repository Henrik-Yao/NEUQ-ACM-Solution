#include <bits/stdc++.h>
using namespace std;
long long a[110], b[110];
int main(void)
{
	int m, n, t, i, j, k;
    cin>>t;
    while(t--)
    {
        cin>>m;
        for(int l=0; l<m; l++)
            cin>>a[l];
        cin>>n;
        for(int l=0; l<n; l++)
            cin>>b[l];
        
        i=j=k=0;
        for(k=0; k<n+m; k++)
        {
            if(a[i]<b[j]&&i!=m&&j!=n)
                cout<<a[i++];
            else if(a[i]>=b[j]&&i!=m&&j!=n)
                cout<<b[j++];
            else if(i==m)
                cout<<b[j++];
            else if(j==n)
                cout<<a[i++];
            if(k<n+m-1)
                cout<<' ';
        }
        cout<<endl;
    }
	
	return 0;
}