#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1,s2,s;
//	getline(cin,s1);
//	getline(cin,s2);
	while(getline(cin,s1)&&getline(cin,s2)){
//        getline(cin,s2)
	map<string,int>p;
	for(int a=0;a<s2.length();a++){
		s=s2[a];
		p[s]=1;
	}
	for(int b=0;b<s1.length();b++){
		s=s1[b];
		if(!p[s])cout<<s1[b];
	}
        cout<<endl;
//	getline(cin,s1);
//	getline(cin,s2);
    }
	return 0;
}
