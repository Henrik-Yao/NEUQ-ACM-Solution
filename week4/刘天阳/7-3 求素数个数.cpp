#include <iostream>
using namespace std;
const int N = 1e7;
bool vis[N];
int main (){
	int n, sum = 0;
	cin >> n;
	vis[1] = 1;
	for (int i = 2; i <= N; i++) {
		if(!vis[i])
			for (int j = 2, k = 1; k <= N; j++) {
				k = i*j;
				if(k <= N)	vis[k] = 1;
			}
	}	
	
	for (int i = 1; i <= n; i++) if(!vis[i]) sum++;
	
	cout << sum;
	
	return 0;
}
