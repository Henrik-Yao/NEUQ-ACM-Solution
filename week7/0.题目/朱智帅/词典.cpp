#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct Dic
{
	string English;
	string Foreign;
};
vector<Dic>V;
int main()
{
	int m, n;
	cin >> n >> m;
	int i;
	string E, F;
	Dic D;
	for (i = 0; i < n; i++)
	{
		cin >> D.English >> D.Foreign;
		V.push_back(D);
	}
	for (i = 0; i < m; i++)
	{
		bool tag = false;
		cin >> F;
		for (int j = 0; j < n; j++)
		{
			if (V[j].Foreign == F)
			{
				tag = true;
				cout << V[j].English << endl;
				break;
			}
		}
		if (!tag) cout << "eh" << endl;
	}
	return 0;
}