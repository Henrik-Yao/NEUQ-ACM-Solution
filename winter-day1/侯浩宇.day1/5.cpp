#include<bits/stdc++.h>
using namespace std;
string a;int n=0,n1=0;
void ppp(){
	for(int i=0;i<n1;i++)cout<<"(";
	for(int i=0;i<a.length();i++)
	cout<<a[i];
	for(int i=0;i<n-n1;i++)cout<<")";
	cout<<endl;
}
void pp(){
	
	for(int i=0;i<a.length();i++){
		if(a[i]=='(')n++;
		else if(n==0)n1++;
		else n--;
	}
	n+=n1;
/**/if(!n) cout<<"Match"<<endl;
	else{
		cout<<n<<endl;
		ppp();
	}
}
int main(){
	while(1){
	if(getline(cin,a)){
		pp();
		for(int i=0;i<a.length();i++)
		a[i]='\0';
	}
	else break;
	}
	return 0;
}
