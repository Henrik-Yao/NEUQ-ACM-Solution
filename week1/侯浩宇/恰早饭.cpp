#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,T,v[100000],t[100000],v1[100000],mv=-1000000;
	cin>>n>>T;
	for(int i=0;i<n;i++){
		cin>>v[i]>>t[i];
		if(t[i] > T) v1[i]=v[i]-(t[i]-T);
		else v1[i]=v[i];
		if(mv<v1[i]) mv=v1[i];
	}
	cout<<mv;
	return 0;
}
