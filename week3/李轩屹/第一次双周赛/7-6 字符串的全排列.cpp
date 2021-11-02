#include<bits/stdc++.h>  
using namespace std;
bool cmp(char a,char b){
	return a<b;
}
int main(){
	string s;
	char a[10];
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++){
		a[i]=s[i];
	}
	sort(a,a+n,cmp);
	do{
		for(int i=0;i<n;i++) cout<<a[i];
		cout<<endl;
	}while(next_permutation(a,a+n));
	return 0;
}
