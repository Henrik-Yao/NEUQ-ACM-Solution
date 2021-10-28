#include<bits/stdc++.h>
#include<string.h>
#include<iostream>
using namespace std;
int main(){
	int n,m,s;
	char a[500000];
	char b[20];
	cin>>n;
	int c[n];
	string d;
	cin>>a;
	getchar();
	for(int i=0;i<n;i++){
    cin>>b;
	m=strlen(b);c[i]=0;s=strlen(a)-m;
    for(int j=0;j<=s;j++){
	d=a[j];
	  for(int k=j+1;k<=j+m-1;k++){
		d=d+a[k];
		} 
		if(d==b) c[i]++;
	}
		
	}
		for(int i=0;i<n;i++){
		cout<<c[i]<<endl;
	}	

	
	
} 
