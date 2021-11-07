#include<bits/stdc++.h>
using namespace std;
int c[200],q;
void px(int x){
	c[q]=x;
	int p=1;
	
	while(p){
		p=0;
		for(int i=1;i<=q;i++){
			if(c[i-1]>c[i]) swap(c[i-1],c[i]),p=1;
		}
	}
}
int main(){
	int t,n,m,a[100],b[100];
	cin>>t;
	for(int i=0;i<t;i++){
/**/		for(int j=0;j<=100;j++)
		a[j]=b[j]=0;
		q=0;
		cin>>n;
		for(int j=0;j<n;j++)
		cin>>a[j];
		cin>>m;
		for(int j=0;j<m;j++)
		cin>>b[j];
/**/		for(int j=0;j<n;j++){
			px(a[j]);q++;
		}
		for(int j=0;j<m;j++){
			px(b[j]);q++;
		}
		for(int j=0;j<q;j++){
			cout<<c[j];
			if(j<q-1)cout<<" ";
		}
		
		cout<<endl;
	}
	return 0;
}
