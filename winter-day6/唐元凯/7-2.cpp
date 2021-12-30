#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct stu
{
	stu() = default;
	stu(string a,int b):
		name(a),score(b){}
	string name;
	int score;
};

int main() {
	vector<stu>a;
	int n;
	cin >> n;
	string t1;
	int t2;
	for (int i = 0; i < n; i++)
	{
		cin >> t1 >> t2;
		a.emplace_back(stu(t1,t2));
	}
	sort(a.begin(), a.end(), [](const stu &s1, const stu &s2) {
		if (s1.score != s2.score)return s1.score > s2.score;
		else return s1.name < s2.name;
		});
	for (auto c : a) {
		cout << c.name << " " << c.score << endl;
	}
}