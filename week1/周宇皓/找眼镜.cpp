      #include<bits/stdc++.h>
using namespace std;
struct glass {
	int a;
	char b[15];
	
};
int main() {
	
	int e,d ,t = 1;
	glass g[100000];
	int m, n;
	cin >> m >> n;
	int c = 0;
	while (m--) {
		c++;
		cin >> g[c].a >> g[c].b;
		
	}
	while (n--) {

		cin >> e >> d;
		if (g[t].a == e){
		
		for (int i = 0; i < d; i++) {
			 {
				t--;
				if (t < 1)
					t += c;
			}
			}}
			else {
					for (int i = 0; i < d; i++) {
					
				t++;
				if (t > c)
					t -= c;
			}}
	 }
	
	cout << g[t].b;
}
