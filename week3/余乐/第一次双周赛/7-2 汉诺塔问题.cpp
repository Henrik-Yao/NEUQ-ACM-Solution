#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
string A,B,C;
int n,T=0;
void y(int t,string a,string b,string c){
	if(t==1){
		cout<<a<<"->"<<c<<endl;
		return;
	}
	y(t-1,a,c,b);
	cout<<a<<"->"<<c<<endl;
	y(t-1,b,a,c);
}
int main(){
	scanf("%d",&n);
	cin>>A>>B>>C;
	y(n,A,B,C);
	return 0;
}
