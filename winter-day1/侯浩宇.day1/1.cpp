#include<bits/stdc++.h>
using namespace std;
int n,q,a[1000001],b1[1000001],b2[1000001],b3[1000001];
void cz2(int i){
	long long ans=0;
	for(int j=b2[i];j<=b3[i];j++)
	ans+=a[j];
	cout<<ans<<endl;
}
int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=q;i++){
		cin>>b1[i]>>b2[i]>>b3[i];
		if(b1[i]==1) a[b2[i]]+=b3[i];
		else cz2(i);
	}
	return 0;
}
