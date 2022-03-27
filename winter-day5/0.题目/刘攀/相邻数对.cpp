#include<bits/stdc++.h>
using namespace std;
int a[10000];
int cou=0;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(a[i]+1==a[i+1]){
			cou++;
		}
	}
	cout<<cou<<endl;
}
