#include<bits/stdc++.h>
using namespace std;

vector<vector<char> > res;
vector<char> now;

void swap(string &s, int a, int b){
	char temp = s[a];
	s[a] = s[b];
	s[b] = temp;
}

void pailie(string s, int pos){
	
	int len = s.size();
	if(pos == len) {
		res.push_back(now);
//		cout << endl;
		return;
	}
	for(int i = pos; i < len; i++){
//		cout << s[i];
		now.push_back(s[i]);
		for(int j = i-1; j >= pos; j--){
			swap(s, j, j+1);
		}
//		swap(s, pos, i);
		pailie(s, pos+1);
		now.pop_back();
		for(int j = pos; j <i; j++){
			swap(s, j, j+1);
		}
//		swap(s, pos, i);
	}
}

int main() {
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	pailie(s, 0);
	for(int i = 0; i < res.size(); i++){
		for(int j = 0; j < res[0].size(); j++){
			printf("%c", res[i][j]);
		}
		cout << endl;
	}

}
