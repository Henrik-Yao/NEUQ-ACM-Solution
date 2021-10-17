#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,i,s=2;
	cin>>n;
	int a[n],cnt1=1,cnt2=0;
	int tong1[100000],tong2[100000];
	for(i=0;i<n;i++){
		cin>>a[i];
		if(i>=1)tong2[a[i]]++;
		if(tong2[a[i]]==1)cnt2++;
	}
	tong1[a[0]]++;
	for(i=1;i<n-1;i++){
		tong1[a[i]]++;
		if(tong1[a[i]]==1)cnt1++;
		if(tong2[a[i]]==1)cnt2--;
		tong2[a[i]]--;
		s=max(s,cnt1+cnt2);
	}
	cout<<s;
	return 0;
}
