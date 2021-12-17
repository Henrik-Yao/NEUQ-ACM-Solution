#include<bits/stdc++.h>
using namespace std;
int n,m,ans,k,p,sum1=0;
int a[10086];
int c[10086];
int main()
{
cin>>n>>m;
for(int i=0;i<=n-1;i++)
 {
 	cin>>a[i];
 }
  sort(a,a+n);
  if(m>=n) ans=n;
  else
    {
  	
  	for(int i=0;i<n-1;i++)
  	  {  c[i]=a[i+1]-a[i]-1;
  	  	
		}
		sort(c,c+n-1);
		ans=a[n-1]-a[0]+1;
		for(int i=n-2;i>n-2-(m-1);i--)
		{
			sum1=sum1+c[i];
		}
		ans=ans-sum1;
    }
	cout<<ans;
	
	
	
	
} 
