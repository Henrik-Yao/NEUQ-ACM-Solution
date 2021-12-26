#include<bits/stdc++.h>
using namespace std;
vector<char>Q;
string kuo(char m){
	char a;
	cin>>a;
	string s="";
	s+=a;
	char b;
	while(cin>>b){
		if(b==')')break;
		else
		Q.push_back(b);
	}
	reverse(Q.begin(),Q.end());
	for(int i=0;i<Q.size();i++){
	    s+=Q[i];
	    s+=a;
    }   
	Q.clear();
	return s;
}
 int main(){
    string s="";
	char a;
	while(cin>>a){
		if(a=='('){
			
			s+=kuo(a);
		}
		else if(a=='B'){
			s+="tsaedsae";
		}
		else if(a=='A'){
			s+="sae";
		}
		else if(a=='#')break;
		else s+=a;
	}
	cout<<s;
	return 0;   
 }
