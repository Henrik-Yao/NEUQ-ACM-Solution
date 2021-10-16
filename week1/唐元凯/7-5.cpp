#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct stu {
	bool dir;
	string name;
};

struct hint
{
	bool dir;
	int num;
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<stu>a;
	vector<hint>b;
	stu temp; hint temp1;
	for (size_t i = 0; i < n; i++)
	{
		cin >> temp.dir >> temp.name;
		a.push_back(temp);
	}
	for (size_t i = 0; i < m; i++)
	{
		cin >> temp1.dir >> temp1.num;
		b.push_back(temp1);
	}
	auto it = a.begin();
	for (size_t i = 0; i < m; i++)
	{
		if (b[i].dir == 0) {
			if ((*it).dir == 0) {
				while (b[i].num--) {
					if (it == a.begin()) {
						it = a.end();
					}
					it--;
				}
			}
			else if((*it).dir == 1){
				while (b[i].num--) {
					if (it == a.end() - 1) {
						it = a.begin();
						b[i].num--;
					}
					it ++;
				}
			}
		}
		else if (b[i].dir == 1) {
			if ((*it).dir == 0) {
				while (b[i].num--) {
					if (it == a.end() - 1) {
						it = a.begin();
						b[i].num--;
					}
					it++;
				}
			}
			else if ((*it).dir == 1) {
				while (b[i].num--) {
					if (it == a.begin()) {
						it = a.end();
					}
					it--;
				}
			}
		}
	}
	cout << (*it).name;
}