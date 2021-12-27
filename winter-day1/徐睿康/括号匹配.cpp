#include<bits/stdc++.h>
using namespace std;
string s;
int cun1,cun2,flag,len;
int main(){
	while(cin>>s){
		cun1=0,cun2=0,flag=0;
		len=s.length();
		for(int i=0;i<len;i++){
			if(s[i]=='(')flag++;
			else flag--;
			if(flag<0){
				cun1++;
				flag=0;
			}
		}
		cun2=flag;
		if(cun1==0&&cun2==0){
			puts("Match");
		}
		else{
			cout<<cun1+cun2<<endl;
			for(int i=1;i<=cun1;i++)cout<<'(';
			cout<<s;
			for(int i=1;i<=cun2;i++)cout<<')';
			cout<<endl;
		}
	}
	return 0;
}
