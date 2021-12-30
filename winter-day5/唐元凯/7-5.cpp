#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

const string male = "sson", female = "sdottir";

struct peo
{
	peo() = default;
	string surname, name;
	char sex;
	peo(string surn, string n) :surname(surn), name(n) {
		if (checksex())sex = 'M';
		else sex = 'F';
	}
	peo(string surn, string n, char sex) :surname(surn), name(n), sex(sex) {}
private:
	bool checksex();
};

unordered_map<string, peo>fa;
vector<peo>p;

int detect(string name1, string name2)
{
	int i = 1;
	for (string A = name1; !A.empty(); A = fa[A].surname, i++)
	{
		int j = 1;
		for (string B = name2; !B.empty(); B = fa[B].surname, j++)
		{
			if (i >= 5 && j >= 5)
				return 1;
			if (A == B && (i < 5 || j < 5))
				return 0;
		}
	}
	return 1;
}

int main() {
	int n;
	cin >> n;
	string t1, t2;
	for (int i = 0; i < n; i++)
	{
		cin >> t1 >> t2;
		p.emplace_back(peo(t2, t1));
	}

	cin >> n;
	string t3, t4;
	for (int i = 0; i < n; i++)
	{
		cin >> t1 >> t2 >> t3 >> t4;
		auto it1 = find_if(p.begin(), p.end(), [&](const peo &t) {return t.name == t1; });
		auto it2 = find_if(p.begin(), p.end(), [&](const peo &t) {return t.name == t3; });
		if (it1 == p.end() || it2 == p.end())cout << "NA" << endl;
		else if ((*it1).sex == (*it2).sex)cout << "Whatever" << endl;
		else {
			//detect part
			if (detect(t1, t3))cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
}

bool peo::checksex()
{
	if (search(surname.begin(), surname.end(), male.begin(), male.end()) != surname.end()) {
		surname.erase(surname.end() - 4, surname.end());
		fa.insert({ name,peo(surname,name,'M') });
		return 1;
	}
	if (search(surname.begin(), surname.end(), female.begin(), female.end()) != surname.end()) {
		surname.erase(surname.end() - 7, surname.end());
		fa.insert({ name,peo(surname,name,'F') });
		return 0;
	}
	if (surname[surname.size() - 1] == 'm') {
		return 1;
	}
	if (surname[surname.size() - 1] == 'f') {
		return 0;
	}
}
