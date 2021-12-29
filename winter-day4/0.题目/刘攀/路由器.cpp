#include<bits/stdc++.h>
using namespace std;
int n,m;
int w[200][200];
int main(){
	while(cin>>n>>m){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			w[i][j]=1000;
		}
	}
	for(int i=0;i<n;i++){
			int t,k,v; 
			cin>>t>>k;
			for(int j=0;j<k;j++){
				cin>>v;
				w[t][v]=1;
			}
	}
	for(int i=0;i<m;i++){
		int a,b;
		int count=1;
		cin>>a>>b;
		for(int j=0;j<n;j++){
			if(w[a][b]>w[a][j]+w[j][b]){
				w[a][b]=w[a][j]+w[j][b];
				count++;
			}
		}
		if(count==1&&w[a][b]!=1){
			cout<<"connection impossible"<<endl;
		}
		else cout<<count<<endl;
	}
}
}
