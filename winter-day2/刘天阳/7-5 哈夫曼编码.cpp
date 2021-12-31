#include <bits/stdc++.h>
using namespace std;
//
priority_queue<int,vector<int>,greater<int> > q;
map<char,int>p;
bool cmp(string s1, string s2)
{
	return s1 < s2;
}
int main()
{
	int m, n, t; cin >> n;
	char c;
	for (int i = 1; i <= n; i++){
		cin >> c >> t;
		p[c] = t;
		q.push(t);
	}
	int ans = 0;
	while(q.size()>1){
		int x = q.top(); q.pop();
		int y = q.top(); q.pop();
		q.push(x+y);
		ans += x+y;
	}
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int sum = 0; char a; string b[1009]; bool ju = 1;
		for (int j = 1; j <= n; j++)
		{
			cin >> a >> b[j]; 
			sum += p[a]*b[j].size();
		}
		if(sum != ans) cout << "No" << endl, ju = 0;
		else {
			sort(b+1,b+n+1,cmp);
			for (int j = 2; j <= n; j++){
				for (int k = 1; k < j; k++){
					if(b[k] == b[j].substr(0,b[k].size())) {
						cout << "No" << endl;
						ju = 0; break;
					}
				}
			if(!ju) break;
			}	
		}
		if(ju) cout << "Yes" << endl;
	}
	return 0;
}
