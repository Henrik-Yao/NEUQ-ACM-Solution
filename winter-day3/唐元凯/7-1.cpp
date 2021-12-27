#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct side
{
	int a, b, w;
};

int main() {
	int n, e;
	cin >> n >> e;
	vector<side>s(e);
	for (size_t i = 0; i < e; i++)
	{
		cin >> s[i].a >> s[i].b >> s[i].w;
	}
	sort(s.begin(), s.end(), [](const side &s1, const side &s2) {if (s1.a != s2.a)return s1.a < s2.a; else if (s1.b != s2.b)return s1.b < s2.b; else return s1.w < s2.w; return true; });
	int cur = -999;
	for (auto &c : s) {
		if (c.a != cur) {
            if (cur != -999)cout << endl;
			cur = c.a;
			cout << cur << ":";
		}
		cout << "(" << c.a << "," << c.b << "," << c.w  << ")";
	}
}