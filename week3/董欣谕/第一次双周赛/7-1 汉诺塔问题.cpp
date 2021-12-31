#include <bits/stdc++.h>
using namespace std;
void hanoi(int n,string a,string b,string c){
	if (n==0) return;
	hanoi(n-1,a,c,b);
	cout<<a<<"->"<<c<<endl;
	hanoi(n-1,b,a,c);
} 
int main(){
	int n;
	cin>>n;
	string a,b,c;
	cin>>a;
	cin>>b;
	cin>>c;
	hanoi(n,a,b,c);
	return 0;
}
