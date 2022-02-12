#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int l=s.length();
    int flag=1;
    for(int i=0;i<l/2;i++){
    	if(s[i]!=s[l-1-i]){
    		flag=0;break;
		}
	}
	if(flag==1) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}
