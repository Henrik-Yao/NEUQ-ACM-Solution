#include<iostream>
#include<string>

using namespace std;

int sum = 0;
int Next[1000005]={0};

void buildNext(string p) {
	int now = 0;
	int i = 1, length = p.length();
	while (i < length)
	{
		if (p[now] == p[i]) {
			now++;
			Next[i] = now;
			i++;
		}
		else if (now)now = Next[now - 1];
		else {
			i++;
			Next[i] = now;
		}
	}
}

void search(string s,string p) {
	int i = 0, pos = 0;
	int slength = s.length(),plength=p.length();
	while (i < slength)
	{
		if (s[i] == p[pos]) {
			i++;
			pos++;
		}
		else if (pos) pos = Next[pos - 1];
		else i++;
		if (pos == plength) {
			sum++;
			pos = Next[pos - 1];
		}
	}
}

int main() {
	string text, pattern;
	cin >> text >> pattern;
	buildNext(pattern);
	search(text,pattern);
	cout << sum;
}