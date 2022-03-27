#include<iostream>
#include<string>

using namespace std;

void hanoi(string begin, string temp,string end, int n) {
	if (n > 1)hanoi(begin, end, temp, n - 1);
	cout << begin << "->" << end << endl;
	if (n > 1)hanoi(temp, begin, end, n - 1);
}

int main() {
	int n; cin >> n;
	string a, b, c; cin >> a >> b >> c;
	hanoi(a, b,c, n);
	return 0;
}