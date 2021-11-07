#include<bits/stdc++.h>
using namespace std;
int n, m, num[100000];
int s[1000][1000];
int ss[1000][1000] = {0};
int x[4] = { 0,1,0,-1};
int y[4] = { 1,0,-1,0};
class node{
public:
	int a = 0, b = 0;
}dir[100000];
queue<node> ssr;
void bfs(){
	for (int i = 0; i < m; i++){
		int max = 1, flag = 0;
		ssr.push(dir[i]);
		if (ss[dir[i].a][dir[i].b] != 0)
			num[i] = num[ss[dir[i].a][dir[i].b] - 1];
		else
		{
			ss[dir[i].a][dir[i].b] = i + 1;
			while (!ssr.empty())
			{
				for (int j = 0; j < 4; j++)
				{
					node temp;
					temp.a = ssr.front().a + x[j];
					temp.b = ssr.front().b + y[j];
					if (s[temp.a][temp.b] == !s[ssr.front().a][ssr.front().b] && temp.a < n && temp.a >= 0 && temp.b >= 0 && temp.b < n && ss[temp.a][temp.b] == 0)//ÅÐ¶¨±ß½ç
					{
						ss[temp.a][temp.b] = i + 1;
						ssr.push(temp);
						max += 1;
					}
				}
				ssr.pop();
			}
			num[i] = max;
		}
	}
}

int main()
{
	string temp;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> temp;
		for (int j = 0; j < n; j++)
			s[i][j] = temp[j] - '0';
	}
	for (int i = 0; i < m; i++){
		cin >> dir[i].a >> dir[i].b;
		dir[i].a -= 1;
		dir[i].b -= 1;
	}
	bfs();
	for(int i=0;i<m-1;i++)
		cout<<num[i]<<endl;
	cout<<num[m-1];
	return 0;
}

