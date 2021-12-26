#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
    int top=0,num=0;
	string str;
	while(cin>>str){
		int len=str.size();
		for (int i=0;i<len;i++)
			if(str[i]=='(') top++;
			else if(top == 0) num++;
			else top--;
		if (top==0 && num==0) cout<<"Match";
		else{
			cout<<num+top<<endl;
			for(int i=0;i<num;i++) cout<<'(';
			cout<<str;
			for(int i=0;i<top;i++) cout<<')';
		}
		cout<<endl;
	}
}
