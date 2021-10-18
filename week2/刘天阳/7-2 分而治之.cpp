#include <iostream>
#include <string.h>

using namespace std;

const int N = 1e4+9;

int s[N], e[N];
bool vis[N];

int main (){
	
	int n, m, k;
	
	cin >> n >> m;
	
	for (int i = 1; i <= m; i++ ){
		cin >> s[i] >> e[i];
	}
	
	cin >> k;
	
	for (int i = 1; i <= k; i++) {
		int sum,v;
		
		cin >> sum;
		
		memset(vis,1,sizeof(vis));
		
		for (int j = 1; j <= sum; j++ ) {
			cin >> v;
			vis[v] = 0;
		}
		
		bool ans = 1;
		
		for (int j = 1; j <= m; j++ ) {
			if(vis[s[j]] && vis[e[j]]) {
				ans = 0;
				break;
			}
		}
		
		if(ans) {
			cout << "YES";
			if(i < k) cout << endl;
		}
		else {
			cout << "NO";
			if(i < k) cout << endl;
		}
	}
	
	
	
	return 0;
}
