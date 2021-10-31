#include <bits/stdc++.h>
using namespace std;
void move(string start,string end){
	printf("%s->%s\n",start.c_str(),end.c_str());
}
void hanoit(int n,string a,string b,string c){
	if(n==1) move(a,c);
	else {
		hanoit(n-1,a,c,b);
		move(a,c);
		hanoit(n-1,b,a,c);
	}
}
int main(){
int n;
string a,b,c; 
cin>>n;
cin>>a;cin>>b;cin>>c;
hanoit(n,a,b,c);
return 0;

}
