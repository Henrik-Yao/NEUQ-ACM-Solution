#include <bits/stdc++.h>
using namespace std;

typedef long long var;
typedef long double let;
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
#define per(i, a, b) for (int (i) = (a); (i) >= (b); --(i))
#define repl(i, t) for (int i = fi[t]; i; i = ne[i])

var read() {
	var a = 0, s = 0, c = getchar();
	while (!isdigit(c)) s |= c == '-', c = getchar();
	while (isdigit(c)) a = a * 10 + c - '0', c = getchar();
	return s ? -a : a;
}

var f[40];

int main() {
#ifndef ONLINE_JUDGE 
	freopen("main.in", "r", stdin);
	freopen("main.out", "w", stdout);
#endif

	f[1] = 2;
	for(int i = 2; i <= 35; ++i) f[i] = 3ll * f[i - 1] + 2ll;

	int n;
	while(cin >> n) 
		cout << f[n] << "\n";
	return 0;
}

/*
CAR:
	make Compile
	make Run

Compile:
	g++ -o main main.cpp -g

Run:
	./main
 */
