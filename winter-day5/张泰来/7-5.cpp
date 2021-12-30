#include <bits/stdc++.h>
using namespace std;
struct node {
	int id,t;
};
pair <string,string> p[100005];
map <string,bool> vis;
map <string,int> id;
map <string,int> sex;
int n,m;
string name1,name2,x1,x2;
int fa[100005],mo[100005];
bool check(int x,int y)
{
	queue <node> q;
	while (!q.empty()) q.pop();
	bool used[100005];
	memset(used,0,sizeof(used));
	node A = {x,1},B = {y,1};
	q.push(A);
	q.push(B);
	used[x] = used[y] = true;
	while (!q.empty())
	{
		node cur = q.front();
		q.pop();
		if (fa[cur.id])
		{
			int father = fa[cur.id];
			if (used[father] || father == x || father == y) return false;
			node C = {father,cur.t + 1};
			if (cur.t < 4) used[father] = true;
			q.push(C);
		}
		if (mo[cur.id])
		{
			int mother = mo[cur.id];
			if (used[mother] || mother == x || mother == y) return false;
			node C = {mother,cur.t + 1};
			if (cur.t < 4) used[mother] = true;
			q.push(C); 
		}
	}
	
	return true;
}

bool find(string s1,string s2)
{
	int len1 = s1.size(),len2 = s2.size();
	if (len1 < len2) return false;
	for (int i = 0;i < len2; i++)
	{
		if (s1[len1 - len2 + i] != s2[i]) return false;
	}
	return true;
}
int main()
{
	cin >> n; 
	for (int i = 1;i <= n; i++)
	{
		cin >> p[i].first >> p[i].second;
		vis[p[i].first] = true;
		id[p[i].first] = i;
		int len = p[i].second.size();
		if (find(p[i].second,"sson") == true || p[i].second[len - 1] == 'm') sex[p[i].first] = 1;
		else sex[p[i].first] = 0;
	}
	for (int i = 1;i <= n; i++)
	{
		int len = p[i].second.size();
		if (find(p[i].second,"sson") == true)
		{
			string s = p[i].second.substr(0,len - 4);
			if (vis[s])
			{
				int t = id[s];
				fa[i] = t;
			}
		}
		
		if (find(p[i].second,"sdottir") == true)
		{
			string s = p[i].second.substr(0,len - 7);
			if (vis[s])
			{
				int t = id[s];
				mo[i] = t;
			}
		}
	}
	
	cin >> m;
	for (int i = 1;i <= m; i++)
	{
		cin >> name1 >> x1 >> name2 >> x2;
		if ((!vis[name1]) || (!vis[name2])) 
		{
			printf("NA\n");
			continue;
		}
		if (sex[name1] == sex[name2])
		{
			printf("Whatever\n");
			continue;
		}
		int x = id[name1],y = id[name2];
		if (check(x,y)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
