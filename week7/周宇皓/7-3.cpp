#include<bits/stdc++.h>
using namespace std;
int b[10001];
string s;
string a;
int main(){
	
while(getline(cin,a)&&getline(cin,s)){
	
for(int i = 0; i < a.length();i++){
	for(int j = 0; j < s.length();j++){
		if(a[i]==s[j])
		b[a[i]]=1;
	}
}
for(int i = 0; i < a.length();i++){
	if(!b[a[i]])
	cout<<a[i];
}
cout<<endl;
memset(b,0,sizeof(b));
a.erase(a.length(),1);
s.erase(s.length(),1);
}
}
