#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,space1[10010],space2[10010],ans;
	cin>>n>>m;
	if(n==1){cout<<1;return 0;}
	for(int i=1;i<=n;i++)
		cin>>space1[i];
	sort(space1+1,space1+n+1);
	ans=space1[n]-space1[1]+1;
	for(int i=2;i<=n;i++)
	    space2[i-1]=space1[i]-space1[i-1];
	sort(space2+1,space2+n);
	for(int i=1;i<m;i++)
		ans=ans-space2[n-i]+1;
	cout<<ans;
	return 0;
}
