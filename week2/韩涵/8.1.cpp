/*#include<iostream>
using namespace std;
void han(string a,string b,string c,int d) {
	if (d > 1)han(a, c, b, d - 1);
	cout << a << "->" << c << endl;
	if (d > 1)han(b, a, c, d - 1);
}
int main() {
	int n;
	cin >> n;
	string name[3];
	for (int i = 0; i < 3; i++) cin >> name[i];
	han(name[0], name[1], name[2], n);
}*/