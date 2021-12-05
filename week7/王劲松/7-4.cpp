#include<bits/stdc++.h>
using namespace std;
int m;
void f(int nn);
int main(){
	int n,i;
	cin>>n;
	for(i=0;i<n;i++){
		m=0;
		int nn;
		cin>>nn;
		f(nn);
		cout<<m<<endl;
		if(i!=n-1)cout<<endl;
	}
	return 0;
}
void f(int nn){
	int ii,a[nn],l[nn];
	for(ii=0;ii<nn;ii++){
		cin>>a[ii];
	}
	for(int j=0;j<nn;j++)l[j]=1;
	for(int j=0;j<nn;j++){
		for(int k=0;k<j;k++){
			if(a[j]>a[k]&&l[j]<l[k]+1)l[j]=l[k]+1;
		}
	}
	for(int j=0;j<nn;j++){
		m=max(m,l[j]);
	}
}
