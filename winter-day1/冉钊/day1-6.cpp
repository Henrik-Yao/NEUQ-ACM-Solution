#include<bits/stdc++.h>
using namespace std;
int main(){
	string a;
	cin>>a;
	string b=a;
	reverse(a.begin(),a.end());
	if(a==b)
		cout<<"yes";
	else
	    cout<<"no";
	return 0;
}
