#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int a[maxn];
int main(){
int n;
cin>>n; 
for(int i=1;i<=n;i++){
	cin>>a[i];
}
int i=1;int ans=0;
while(1){
int	p=i;
int m=0;ans++;
for(int j=p+1;j<=p+a[p]&&j<=n;j++){
	       if((a[j]+j)>=m){
	       	i=j;m=a[j]+j;
		   }
	}
	if(i+a[i]>=n) {ans++;
	break;}
}
cout<<ans;


return 0;

}
