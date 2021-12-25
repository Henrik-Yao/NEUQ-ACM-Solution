#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<queue>
#include<iomanip>
#include<algorithm>
using namespace std;

struct person
{
	string name;
	int dest, uset,wait=0; // 到达时间dest，所需时间uset
	bool ok = 0; 
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<set<string>>fc(m);
	vector<person>pe(n);
	string temp;
	for (size_t i = 0; i < m; i++)
	{
		int ii;
		cin >> ii;
		for (size_t j = 0; j < ii; j++)
		{
			cin >> temp;
			fc[i].insert(temp);
		}
	}
	for (size_t i = 0; i < n; i++)
	{
		cin >> pe[i].name >> pe[i].dest >> pe[i].uset;
		if (pe[i].uset > 60)pe[i].uset = 60;
	}
	queue<person *>qu;
	int finisht = pe[0].dest;
	for (size_t i = 0; i < n; i++)
	{
		if (pe[i].ok)continue;
		qu.push(&pe[i]);
		if (pe[i].dest > finisht)finisht = pe[i].dest;
		pe[i].wait = finisht - pe[i].dest;
		finisht += pe[i].uset;
		pe[i].ok = 1;
		//find friend
		for (auto &c : fc) {
			if (c.find(pe[i].name) != c.end())
				for (size_t j = i + 1; j < n; j++)
					if (c.find(pe[j].name) != c.end())
						if (pe[j].ok == 0 && pe[j].dest <= finisht) {
							qu.push(&pe[j]);
							pe[j].wait = finisht - pe[j].dest;
							finisht += pe[j].uset;
							pe[j].ok = 1;
						}
		}
	}
	double sum = 0;
	for (size_t i = 0; i < n; i++)
	{
		cout << (*qu.front()).name << endl;
		sum += (*qu.front()).wait;
		qu.pop();
	}
	cout << fixed << setprecision(1) << sum / n;
}


