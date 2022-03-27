#include<bits/stdc++.h>
using namespace std;
int main(){
     int t,m,n,j=0,k=0,x=0;
	 cin>>t;
	 while(t--){
         cin>>m;
		 int a[m];
		 for(int i=0;i<m;i++)
		 cin>>a[i];

		 cin>>n;
		 int b[n];
		 for(int i=0;i<n;i++)
		 cin>>b[i];

		 int s[m+n];
		 j=0,k=0,x=0;
		 while(j<m&&k<n){
			 if(a[j]<=b[k])
			 s[x++]=a[j++];

			 else
			 s[x++]=b[k++];
		 }
		 while(j<m)
		 s[x++]=a[j++];

		 while(k<n)
		 s[x++]=b[k++];

		 for(int i=0;i<m+n-1;i++)
		 cout<<s[i]<<" ";

		 cout<<s[m+n-1]<<endl;
          
	 }
return 0;
}