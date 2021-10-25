#include<iostream>
using namespace std;
struct xuhao{
	int b;
	int c;
	
}a[10010];
int h[10010];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i].b>>a[i].c;
	}
	int t,k,q;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>q;
			h[q]=1;
			
		}
		int flag=0; int z,x;
		for(int l=1;l<=m;l++){z=a[l].b;
		x=a[l].c;
			if(h[z]!=1&&h[x]!=1) flag=1;
		}
		for(int j=1;j<=n;j++){
			
			h[j]=0;
			
		}
		if(flag==0) cout<<"YES"<<endl;
		if(flag==1) cout<<"NO"<<endl;
		
	}
	
	
	
	
	
}
