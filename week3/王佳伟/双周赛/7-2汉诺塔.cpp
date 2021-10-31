#include<bits/stdc++.h>
using namespace std;


void hanshu(int n, string now, string to, string third){
	if(n == 0) return;
	hanshu(n-1, now, third, to);
	cout << now << "->" << to << endl;
	hanshu(n-1, third, to, now);
}

int main() {
	int n;
	string a,b,c;
	cin >> n;
	cin >> a >> b >> c;
	hanshu(n, a, c, b);
}
