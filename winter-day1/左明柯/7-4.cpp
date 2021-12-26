#include <bits/stdc++.h>
using namespace std;
vector<int>a[2];
int main(){
	int x[10086];int p=0;
	while(cin>>x[p++]);
	sort(x,x+p);
	for(int i=0;i<p;i++){
		if(x[i]!=0){
		cout<<x[i];
		if(i!=p-1) cout<<"->";
		if(x[i]%2==0) a[0].push_back(x[i]);
		else a[1].push_back(x[i]);
	}}
	cout<<endl;
	int L1=a[0].size();
	int L2=a[1].size();
	for(int i=0;i<L2;i++){
		if(a[1][i]!=0){
		if(i!=L2-1) cout<<a[1][i]<<"->";
		else cout<<a[1][i];
	}};
	cout<<endl;
	for(int i=0;i<L1;i++){
		if(a[0][i]!=0){
		if(i!=L1-1) cout<<a[0][i]<<"->";
		else cout<<a[0][i];
	}}
	
	
	
	
	
	
	
	return 0;
}
