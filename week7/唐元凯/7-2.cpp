#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string s;
int length;

void loop1(int n, int start) {
	string stemp; bool flag = 0;
	for (size_t i = 0; i < n-1; i++)
	{
		flag = 0;
		for (size_t j = start+1; j < length; j++) {
			if (s[j] == '[') {
				if (isdigit(s[j + 1])) {
					stemp += s[j + 1];
					j++;
					if (isdigit(s[j + 1])) {
						stemp += s[j + 1];
						j++;
					}
				}
				else {
					cout << s[j]; flag = 1; 
					continue;
				}
				loop1(stoi(stemp), j);
				stemp = "";
			}
			else if (s[j] == ']'&&!flag)break;
			else cout << s[j];
		}
	}
}

int main() {
	string ss, stemp; bool flag = 0;
	cin >> s;
	length = s.length();
	for (size_t i = 0; i < length; i++)
	{
		if (s[i] == '[') {
			if (isdigit(s[i + 1])) {
				stemp += s[i + 1]; 
				i++;
				if (isdigit(s[i + 1])) {
					stemp += s[i + 1];
					i++;
				}
			}
			else {
				cout << s[i]; flag = 1;
				continue;
			}
			loop1(stoi(stemp),i);
			stemp = "";
		}
		else if (s[i] == ']' && !flag) {
			continue;
		}
		else cout << s[i];
	}
}