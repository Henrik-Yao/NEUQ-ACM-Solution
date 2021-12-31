#include <iostream>
#include <string>

using namespace std;

void hnt(string s, string e, string m, int n) {
	if(n == 1) cout << s << "->" << e << endl;
	else {
		hnt(s, m, e, n-1);
		hnt(s, e, m, 1);
		hnt(m, e, s, n-1);
	}
}

int main (){
	
	string a, b, c;
	int n;
	
	cin >> n >> a >> b >> c;
	
	hnt(a, c, b, n);
	
	return 0;
}
