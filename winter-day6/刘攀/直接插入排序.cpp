#include<bits/stdc++.h>
using namespace std;
int a[100001];
int n;
void insertsort(){
	int temp;
	int i;
	int j;
	for(i=1;i<n;i++){
		temp=a[i];
		for(j=i-1;j>=0&&a[j]>temp;j--){
			a[j+1]=a[j];
		}
		a[j+1]=temp;
		for(int i=0;i<n;i++){
			cout<<a[i];
			if(i!=n-1) cout<<" "; 
		}
		cout<<endl;
	}
}
int main(){
	while(cin>>n){
		memset(a,0,sizeof(a));
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	insertsort();
}
}
