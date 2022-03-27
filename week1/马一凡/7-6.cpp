#include<iostream>
#include<cstring>
using namespace std;

int main(){
	long long T,v,n,t,a=0,i,k;
	cin >> n >> T;
	for(i=0; i<n; i++){
		cin >> v >> t;
		if(t>T) k = v-(t-T);
		else k = v;
		if(i==0) a = k;
		if(k>a) a = k;
	}
	cout << a;
	
	return 0;
}
