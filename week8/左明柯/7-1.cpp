#include <bits/stdc++.h>
using namespace std;
struct pp{
	int begin,end;
}a[100];
bool cmp(struct pp p1,struct pp p2){
	return p1.end<p2.end;
}
int main(){
int T;int n;
cin>>T;
while(T--){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].begin>>a[i].end;
	}
	sort(a+1,a+n+1,cmp);
	int j=1;int ans=1;
	for(int i=2;i<=n;i++){
	if(a[i].begin>=a[j].end){
		j=i;ans++;
	}
}
cout<<n-ans<<endl;}
	return 0;}
	
