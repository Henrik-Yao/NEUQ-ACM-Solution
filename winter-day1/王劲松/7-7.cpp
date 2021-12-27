#include<bits/stdc++.h>
using namespace std;
string s;
int f(int i);
int main(){
	//string s;
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++){
		char ss=s[i];
		if(ss=='B')cout<<"tsaedsae";
		if(ss=='A')cout<<"sae";
		if(ss=='(')i=f(i);
		if(ss=='#'){
            cout<<endl;
            break;
        }
	}
	return 0;
}
int f(int i){
	string si;
	int nn=0;
	while(s[++i]!=')'){
		si+=s[i];
		nn++;
	}
	for(int cnt=nn-1;cnt>0;cnt--){
		cout<<si[0]<<si[cnt];
	}
	cout<<si[0];
	return i;
}
