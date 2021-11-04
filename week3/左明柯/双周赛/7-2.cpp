#include <bits/stdc++.h>
using namespace std;
void move(string begin,string end){
	printf("%s->%s\n",begin.c_str(),end.c_str());
}
void hanoi(int n,string a,string b,string c){
	if(n==1) move(a,c);
	else {
	hanoi(n-1,a,c,b);
	move(a,c);
	hanoi(n-1,b,a,c);
}
}

int main(){
	int n;
	cin>>n;
	string a,b,c;
	cin>>a>>b>>c;
	hanoi(n,a,b,c);
	return 0;
}
