#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,e;
	int a[60]={0};
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> e;
		a[e]++;
	}
	for(int i=0; i<60; i++){
		if(a[i]!=0){
			cout << i << ":" << a[i] << endl;
		}
	}
	
	return 0;
}
