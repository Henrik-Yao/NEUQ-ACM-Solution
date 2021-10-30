#include<bits/stdc++.h>
using namespace std;
int n,lens,lens1,flag,cnt;
string s,s1;
int main(){
	cin>>n;
	cin>>s;
	lens=s.length();
	while(n--){
		cin>>s1;
		lens1=s1.length();
		cnt=0;
		for(int i=0;i<lens;i++){
			if(s[i]==s1[0]){
				flag=0;
				for(int j=i;j<i+lens1;j++){
					if(s[j]!=s1[j-i]){
						flag=1;
						break;
					}
				}
				if(flag==0)cnt++;
			}
		}
		if(n!=0)
		cout<<cnt<<endl;
		else
		cout<<cnt;
	}
	return 0;
}
