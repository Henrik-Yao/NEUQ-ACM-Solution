#include<bits/stdc++.h>
using namespace std;

int main(){
	string a,a1,a2;
	cin>>a;
	for(int i=0;i<a.length();i++){
		a1[i]=a[i],a2[i]=a[a.length()-i-1];
		if(a1[i]!=a2[i]){
			cout<<"no";
			return 0;
		}
	}
	cout<<"yes";
	return 0;
}
