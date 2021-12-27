#include <bits/stdc++.h>
using namespace std;
const int N = 1009;
int n, a[N], lc[N], rc[N], tim = 0, ans = 0;
void zhong(int x, int d)
{
	if(a[lc[x]]) zhong(lc[x], d+1);
	ans = max(ans, d);
	if(!tim) cout << a[x];
	else cout << " " << a[x];
	tim++;
	if(a[rc[x]]) zhong(rc[x], d+1);
}
int main(){
	int t; cin >> t;
	while(t--)
	{
		ans = 0;
		cin >> n;
		memset(lc, 0, sizeof(lc));
		memset(rc, 0, sizeof(rc));
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if(i*2 <= n) lc[i] = i*2;
			if(i*2+1 <= n) rc[i] = i*2+1;
		}
		tim = 0;
		zhong(1, 1);
		int k = 0;
		while(n){
			n>>=1;
			k++;
		}
		cout << k << endl;
//		cout << endl << ans << endl;
	}
	
	return 0;
}
