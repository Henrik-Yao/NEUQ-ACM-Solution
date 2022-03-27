#include<bits/stdc++.h>
using namespace std;
bool c[10000010];
int main()
{    int n,sum=0;
    cin>>n;
	for(int i=2;i<=n;++i)
	{ if(c[i]) continue;
	++sum;
		for(int j=i;j<=n;j+=i){
			c[j]=1;
		}
	
		
	}
	
	cout<<sum<<endl;
	}
 

