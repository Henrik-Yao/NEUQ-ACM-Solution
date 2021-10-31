#include<bits/stdc++.h>
using namespace std;
int c[10010];
int a[10010];
int b[10010];
int main()
{
	int n,m,k;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i];
	 } 
	 cin>>k;
	 while(k--)
	 {
	 	int k1,flag=0,l;
	 	cin>>k1;
	 	memset(c,0,sizeof(c));
	 	for(int i=1;i<=k1;i++)
	 	{
	 		cin>>l;
	 		c[l]=1;//È¥³ý 
		 }
		 for(int i=1;i<=m;i++)
		 { 
		 	if(c[a[i]]||c[b[i]])
		 	{
			   
		 		continue;     
			}
			 else 
			 {
			 	flag=1;
			
			 }
		 }
		 if(flag) cout<<"NO"<<endl;
		 else cout<<"YES"<<endl;
	 }
	 return 0;
} 
