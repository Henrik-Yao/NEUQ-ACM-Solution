#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	while(cin>>s){
		stack<char>z;
		int i=0,n=s.length();
		int q=0,h=0;
		for(;i<n;i++){
			if(s[i]=='(')z.push(s[i]);
			if(s[i]==')'&&z.empty())q++;
			if(s[i]==')'&&!z.empty())z.pop();
		}
		if(!z.empty()){
			h+=z.size();
		}
		if(q+h==0)cout<<"Match";
		if(q+h!=0){
			cout<<q+h<<endl;
			for(i=0;i<q;i++)cout<<'(';
			cout<<s;
			for(i=0;i<h;i++)cout<<')';
		}cout<<endl;
	}
	
	return 0;
}
