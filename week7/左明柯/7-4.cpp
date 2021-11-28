#include <bits/stdc++.h>
using namespace std;
const int N=1005; 
int main(){
	int num,n;int a[N],f[N];
	cin>>num;int t=num;
	while(num--){
		if(num!=t-1) cout<<endl;
		cin>>n;
		for(int i=1;i<=n;i++){
             cin>>a[i];}
             int ans=0;
             for(int i=1;i<=n;i++){
             	f[i]=1;
             	for(int j=1;j<=i-1;j++)
             	if(a[j]<a[i]) f[i]=max(f[i],f[j]+1);
             	ans=max(ans,f[i]);
			 }
			 cout<<ans<<endl;
	}
	
return 0;

}
