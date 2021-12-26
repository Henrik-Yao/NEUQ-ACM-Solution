#include<bits/stdc++.h>
using namespace std;
string a;
bool p=1;
void pp1(){
	int n,n1;
	n=n1=0;
	for(int i=0;i<a.length();i++){
		if(a[i]=='(')n++;
		else if(a[i]==')')
		if(n==0)n1++;
		else n--;
	}
	n+=n1;
/**/if(n){
		p=0;return;
	}
}
void pp2(){
	int n,n1;
	n=n1=0;
	for(int i=0;i<a.length();i++){
		if(a[i]=='[')n++;
		else if(a[i]==']')
		if(n==0)n1++;
		else n--;
	}
	n+=n1;
/**/if(n){
		p=0;return;
	}
}
void pp3(){
	int n,n1;
	n=n1=0;
	for(int i=0;i<a.length();i++){
		if(a[i]=='{')n++;
		else if(a[i]=='}')
		if(n==0)n1++;
		else n--;
	}
	n+=n1;
/**/if(n){
		p=0;return;
	}
}
int main(){
	cin>>a;
	pp1();
	pp2();
	pp3();
	if(p)cout<<"yes";
	else cout<<"no";
	return 0;
}
