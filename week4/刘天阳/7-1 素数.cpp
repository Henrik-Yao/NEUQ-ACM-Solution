#include <iostream>
using namespace std;
const int N = 1e5+9;
bool vis[N];
int main (){
	vis[1] = 1;
	for (int i = 2; i <= 10000; i++) {
		if(!vis[i])
			for (int j = 2, k = 1; k <= 10000; j++) {
				k = i*j;
				vis[k] = 1;
			}
	}	
	
	int a, b;
	while(cin >> a >> b) {	
		bool j = 0;
		int k;
		for (int i = b; i >= a; i--) {
			if(!vis[i]) {
				k = i;
				break;
			}
		}
		for (int i = a; i <= b; i++) if(!vis[i]) {
			cout << i;
			j = 1;
			if(i != k) cout << " ";
		}
		if(j) cout << endl;
	}
	
	return 0;
}
