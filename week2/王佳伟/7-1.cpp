#include<bits/stdc++.h>
using namespace std;

string a[3];
void move(int n, int now, int to){
	if(n == 0) return;
	move(n-1, now, 3-now-to);
	cout << a[now] << "->" << a[to] << endl;
	move(n-1, 3-now-to, to);
}

int main() {
	int n; 
	cin >> n;
	
	for(int i = 0; i < 3; i++){
		cin >> a[i];
	} 
	move(n, 0, 2);
}
