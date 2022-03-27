#include<bits/stdc++.h>
using namespace std;
struct customer{
	string name;
	int atim, tim;
}cus[10009];
map<string,int>f;//可以访问到朋友圈friendMap
map<string,int>fm;//customerId 次序;
bool vis[10009];
vector<string>fri[10009],ans;
 bool cmp(string s1, string s2)
 {
 	return fm[s1] < fm[s2];
 }
int main()
{
	int n,m; cin >> n >> m;
	for (int i = 1; i <= m; i++) 
	{
		int k;
		string nam;
		cin >> k;
		while(k--) 
		{
			cin >> nam;
			f[nam] = i;
			fri[i].push_back(nam);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> cus[i].name >> cus[i].atim >> cus[i].tim;
		if(cus[i].tim>60) cus[i].tim = 60;
		fm[cus[i].name] = i;
	}
	int sum = 0, wit = cus[1].atim;
	for (int i = 1; i <= n; i++)
	{
		if(vis[i]) continue;
		if(f.find(cus[i].name) == f.end())
		{
			if(wit > cus[i].atim)
			{
				sum += wit - cus[i].atim;
				wit += cus[i].tim;
			}
			else 
			{
				wit = cus[i].atim + cus[i].tim;
			}
			vis[i] = 1;
			ans.push_back(cus[i].name);
			continue;
		}
		int qvan = f[cus[i].name];
		sort(fri[qvan].begin(),fri[qvan].end(),cmp);
		for (int j = 0; j < fri[qvan].size(); j++)
		{
			int id = fm[fri[qvan][j]];
			if(j>0 && cus[id].atim > wit) break;
			if(vis[id]) continue;
			if(wit > cus[id].atim)
			{
				sum += wit - cus[id].atim;
				wit += cus[id].tim;
			}
			else 
			{
				wit = cus[id].atim + cus[id].tim;
			}
			vis[id] = 1;
			ans.push_back(fri[qvan][j]);
		}
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	printf("%.1f\n",sum*1.0/n);
	return 0;
}
