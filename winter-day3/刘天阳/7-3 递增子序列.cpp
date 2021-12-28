#include <bits/stdc++.h>
using namespace std;
int a[200], b[200];int n;
vector<int>ans[200009];
int cnt = 0;
void dfs(int x, int t, int b[])
{
	b[t] = a[x];
	
	if(t >= 2)
	{	
		int ju = 1, tt = 0;
		
		for (int i = 1; i <= cnt; i++)
		{
			tt = 0;
			
			if(t == ans[i].size())
				for (int j = 0; j < t; j++)
					if(ans[i][j] == b[j+1]) tt++;
					
			if(tt == t) 	ju = 0;
		}
		
		if(ju){
			cnt++;
			for (int j = 1; j <= t; j++) ans[cnt].push_back(b[j]);
		}
	}
	
	for (int i = x+1; i <= n; i++) if(a[i] >= a[x])dfs(i,t+1,b);
}
int main()
{
	 cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) dfs(i, 1, b);
//	for (int i = 1; i <= cnt; i++)
//	{
//		printf("i = %d:",i);
//		for (int j = 0; j < ans[i].size(); j++)
//		cout << ans[i][j] << " ";
//		cout << endl;
//	}
	cout << cnt;
	return 0;
}
