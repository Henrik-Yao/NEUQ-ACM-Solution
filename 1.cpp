#include <bits/stdc++.h>
using namespace std;
void hanoi(int plate,string st,string nd,string rd) {
	if (plate==1) {
		cout<<st<<"->"<<rd<<endl;
	} else {
		hanoi(plate-1,st,rd,nd);
		cout<<st<<"->"<<rd<<endl;
		hanoi(plate-1,nd,st,rd);
	}
}

int main() {
	int n;
	cin>>n;
	string a,b,c;
	cin>>a>>b>>c;
	hanoi(n,a,b,c);
	return 0;
}
