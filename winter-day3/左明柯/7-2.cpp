#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	map<int,map<int,int>>hh;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		hh[a][b]=c;
	}
	int k;
	cin>>k;
	for(int i=0;i<k;++i){
		int a,b;
		cin>>a>>b;
		hh[a].erase(b);
	}
	
	for(auto i:hh){
		int a=i.first;
		if(!i.second.empty()) cout<<a<<":";
		for(auto j:i.second){
		printf("(%d,%d,%d)",a,j.first,j.second);									
		}
		if(!i.second.empty()) cout<<endl;
		
	}
	
	
	
	
	
	
	
	
	
	return 0;
}
