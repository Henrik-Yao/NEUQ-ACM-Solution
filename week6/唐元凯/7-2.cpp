#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;
string weakhash(string s);
void log(string name, string pass);
void sign(string name, string pass);
int fsum(string temp);
char tran(int s);

unordered_map<string, string>db;

void sign(string name,string pass) {
	auto ret=db.insert({ name,pass });
	if (ret.second)cout << "Signed!";
	else cout << "Repeated!";
}

void log(string name, string pass) {
	if (db.find(name) == db.end())cout << "Failed!";
	else if (db[name] == pass)cout << "Success!";
	else {
		string h1 = weakhash(db[name]);
		string h2 = weakhash(pass);
		if (h1 == h2)cout << "Attention!";
		else cout << "Failed!";
	}
}

string weakhash(string s) {
	int len = s.length(), sum = 0;
	int floor = len / 4;
	int num = len - 4 * floor;
	string temp,ssum;
	for (int i = 0; i < 4; i++) {
		sum = 0;
		if (num > 0) {
			temp = s.substr(0, floor + 1); 
			num--;
			sum = fsum(temp);
			s.erase(0, floor + 1);
		}
		else {
			temp = s.substr(0, floor);
			sum=fsum(temp);
			s.erase(0, floor);
		}
		temp = tran(sum);
		ssum += temp;
	}
	return ssum;
}

int fsum(string temp) {
	int sum = 0;
	for (auto c : temp) {
		if (isdigit(c))sum += (int)(c - '0');
		else if (isupper(c))sum += ((int)(c - 'A') + 10);
		else if (islower(c))sum += ((int)(c - 'a') + 10);
	}
	return sum;
}

char tran(int s) {
	char temp;
	while (true) {
		if (s > 35)s -= 36;
		else {
			if (s >= 0 && s <= 9)temp = char(s);
			else temp = (char)(97 + (s - 10));
			break;
		}
	}
	return temp;
}

int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	char op;;
	string name, pass;
	while (N--)
	{
		cin >> op>>name>>pass;
		if (op == 'R')sign(name, pass);
		else log(name, pass);
		cout << endl;
	}
}