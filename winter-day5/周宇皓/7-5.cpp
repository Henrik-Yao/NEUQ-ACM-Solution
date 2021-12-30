#include<iostream>
#include<map>
#include<string>
using namespace std;
struct Peoson {
	char sex;
	string father;
};
map<string, Peoson> people;
int judge(string a, string b) {
	int i = 1, j;
	for (string A = a; !A.empty(); A = people[A].father, i++) {
		j = 1;
		for (string B = b; !B.empty(); B = people[B].father, j++) {
			if (i >= 5 && j >= 5)		break;	
			if (A == B && (i < 5 || j < 5))     
				return 0;
		}
	}
	return 1;
}
int main() {
	int n, m;
	string str, a, b;
	cin.sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (b.back() == 'n') 				
			people[a] = { 'm',b.substr(0,b.size() - 4) };
		else if (b.back() == 'r')			
			people[a] = { 'f',b.substr(0, b.size() - 7) };
		else	people[a].sex = b.back();	
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> str >> b >> str;  
		if (people.find(a) == people.end() || people.find(b) == people.end())		printf("NA\n");
		else if (people[a].sex == people[b].sex)		printf("Whatever\n");
		else	printf("%s\n", judge(a, b) ? "Yes" : "No");
	}
	return 0;
}
