#include <bits/stdc++.h>
using namespace std;
const int N = 1009;
int g[N][N], du[N];

int main(){
	int n, m;
	while(cin >> n >> m)
	{
		memset(du, 0, sizeof(du));
		memset(g, 0, sizeof(g));
		int a, b; 
		for (int i = 1; i <= m; i++){
			cin >> a >> b;
			g[a][b] = 1; du[b]++;
		}
		
		
		int ju = 0;   
		for (int i = 1; i <= n; i++)
		{
			ju = max(du[i], ju);
		}
		int t = ju;
		
		int tmp = 0, cnt = 0;
		queue<int>st;
		{
			for (int i = 1; i <= n; i++)
				if(!du[i]) st.push(i);
			while(!st.empty())
			{
				if(st.size()>=2) tmp = 1;
				int x = st.front();
				st.pop();
				cnt++;
				for (int i = 1; i <= n; i++)
				{
					if(g[x][i]) 
					{
						g[x][i] = 0;
						du[i]--;
						if(!du[i]) st.push(i);
					}
				}
			}
			
			if(cnt != n) cnt = 0;
			else cnt = 1+tmp;
			cout << cnt << endl;
		} 
	}
	return 0;
}
