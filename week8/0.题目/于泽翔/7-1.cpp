#include <bits/stdc++.h>
using namespace std;
int t, n, a[999], z[999];
int main(void)
{
    cin>>t;
    while(t--)
    {
        int w=1;
    	cin>>n;
		for(int i=0; i<n; i++)
			cin>>a[i]>>z[i];
		
		for(int i=0; i<n-1; i++)
			for(int j=0; j<n-1-i; j++)
				if(z[j]>z[j+1])
					swap(a[j], a[j+1]), swap(z[j], z[j+1]);
		int j=0;
		for(int i=1; i<n; i++)
			if(a[i]>=z[j])
				j=i, w++;
		cout<<n-w<<endl;
	}
    
	return 0;
}