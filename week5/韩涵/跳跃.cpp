/*#include<iostream>
using namespace std;

int road[100001];
int OK[10001];
bool flag = false;

void jumping(int a) {
	OK[a] = false;
	if (road[a] == 0) {
		flag = true;
		return;
	}
	else {
		if (a - road[a] > 0 && OK[a - road[a]]) jumping(a - road[a]);
		if (a + road[a] > 0 && OK[a + road[a]]) jumping(a + road[a]);
	}
}

int main() {
	int n,start;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		OK[i] = true;
		cin >> road[i];
	}
	cin >> start;
	jumping(++start);
	if (flag) cout << "True";
	else cout << "False";
}*/