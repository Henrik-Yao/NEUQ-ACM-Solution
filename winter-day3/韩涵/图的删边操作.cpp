#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct side {
	int x;
	int y;
	int weight;
};

bool cmp(const side& s1, const side& s2) {
	if (s1.x != s2.x)return s1.x < s2.x;
	else if (s1.y != s2.y) return s1.y < s2.y;
	else return s1.weight < s2.weight;
	return true;
}

int main() {
	int n, e;
	cin >> n >> e;
	vector <side> v(e);
	for (size_t i = 0; i < e; i++)
	{
		cin >> v[i].x >> v[i].y >> v[i].weight;
	}
	sort(v.begin(), v.end(), cmp);
	int k, ta, tb;
	cin >> k;
	while (k--) {
		cin >> ta >> tb;
		auto it = find_if(
			v.begin(),
			v.end(),
			[&ta, &tb](const side& s) { return (s.x == ta && s.y == tb); }
		);
		v.erase(it);
	}
	int cur = -999;
	for (auto& c : v) {
		if (c.x != cur) {
			if (cur != -999)cout << endl;
			cur = c.x;
			cout << cur << ":";
		}
		cout << "(" << c.x << "," << c.y << "," << c.weight << ")";
	}
}