#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	getline(cin,s);
	int n = s.length(), flag=0;
	for(int i=0; i<n; i++) 
		if(s[i]!=s[n-i-1]) {
			flag = 1;
			break;
		}
	if(!flag) puts("yes");
	else puts("no");
    return 0;
}

