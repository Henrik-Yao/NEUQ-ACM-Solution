#include<bits/stdc++.h>
using namespace std;
int w[510];
string s1,s2;
int main(){
	while(getline(cin,s1)){
		getline(cin,s2);
		memset(w,0,sizeof(w));
		//cout<<s1.length()<<' '<<s2.length();
		for(int i=0;i<s2.length();i++){
			w[s2[i]]=1;
		}
		for(int i=0;i<s1.length();i++){
			if(w[s1[i]]==1)continue;
			else cout<<s1[i];
		}
		cout<<endl;
	}
	return 0;
}
