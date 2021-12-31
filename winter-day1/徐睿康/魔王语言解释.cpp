#include<bits/stdc++.h>
using namespace std;
string s;
char c,a[10000010];
int len,cnt=0;
int main(){
	cin>>s;
	len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]=='B')cout<<"tsaedsae";
		if(s[i]=='('){
			cnt=0;
			i++;
			c=s[i];
			while(1){
				i++;
				if(s[i]==')'){
					cout<<c;
					for(int j=cnt;j>=1;j--){
						cout<<a[j]<<c;
					}
					break;
				}
				else {
					cnt++;
					a[cnt]=s[i];
				}
			}
		}
	}
	return 0;
}
