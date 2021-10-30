#include<iostream>
#include<cstdio>
using namespace std ;
int main(){
	int n,T,max;
	cin>>n>>T;
	int a[n][2],v[n];
	for(int i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	for(int i=0;i<n;i++){
		if(a[i][1]<T) v[i]=a[i][0];
		else v[i]=a[i][0]-(a[i][1]-T);
	}
	max=v[0];
	for(int i=1;i<n;i++){
		if(v[i]>max) max=v[i];
		else;
		
		
	}
	printf("%d",max);
	
	
	return 0;
}
