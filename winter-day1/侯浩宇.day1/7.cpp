#include<bits/stdc++.h>
using namespace std;
string a,ans;
void f1(){
	ans+="tsaedsae";
}
void f2(){
	ans+="sae";
}
void f3(int beginn){
	int endd,i;
	for( i=beginn;i<a.length();i++){
	//	cout<<1;,cout<<beginn
		while(a[i]==')')break;
	}endd=i-beginn;
	//ans+=a[beginn];
	for(int i=endd-1;i>beginn;i--){
		if(a[i]=='B')f1();
		if(a[i]=='A')f2();
		if(a[i]>='a'&&a[i]<='z')ans+=a[i];
		if(a[i]=='('){
			f3(i);
			while(a[i]!=')')i++;
		}
		ans+=a[beginn];
	}	
}
int main(){
	cin>>a;
    ans="";
	for(int i=0;i<a.length();i++){
		if(a[i]=='B')f1();
		if(a[i]=='A')f2();
		if(a[i]=='('){
			f3(i+1);
			while(a[i]!=')')i++;
		}
	}		
	cout<<ans<<endl;
	return 0;
}
