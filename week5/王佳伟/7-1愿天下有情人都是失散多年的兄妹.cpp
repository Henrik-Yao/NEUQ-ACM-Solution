#include<bits/stdc++.h>
using namespace std;

int n, k;
struct P{
	string id;
	char gen;
	string f, m;
	P(){}
	P(string id, char gen, string f, string m){
		this->id = id;
		this->gen = gen;
		this->f = f;
		this->m = m;
	}
};
unordered_map<string, P> mp;

void dfs(string peo, int num, bool &suc, unordered_map<string, bool> &book){
	if(!suc || peo.empty() || num >= 6 || peo == "-1") return;
	if(book[peo] == false){
		book[peo] = true;
		dfs(mp[peo].f, num+1, suc, book);
		dfs(mp[peo].m, num+1, suc, book);
	}
	else{
//		cout << "this is" << peo << endl;
		suc = false;
		return;
	}
}

int main() {
	cin >> n;
	string a, b, c;
	char d;
	for(int i = 0; i < n; i++){
		cin >> a >> d >> b >> c;
//		mp[a] = P(a, d, b, c);
		mp[a].id = a;
		mp[a].gen = d;
		mp[a].f = b;
		mp[a].m = c;
		mp[b].gen = 'M';
		mp[c].gen = 'F';
	}
//	cout << "............." << endl;
//	cout << mp["00001"].f << endl;
//	cout << mp["00001"].m << endl;
	
	cin >> k;
	string man, woman;
	for(int i = 0; i < k; i++){
		bool suc = true;
		cin >> man >> woman;
		if(mp[man].gen == mp[woman].gen){
			cout << "Never Mind";
			if(i != k-1) cout << endl;
			continue;
		}
		unordered_map<string, bool> book;
		dfs(man, 1, suc, book);
		dfs(woman, 1, suc, book);
		if(suc) cout << "Yes";
		else cout << "No";
		if(i != k-1) cout << endl;
	}
	 
}
/*
24
00001 M 01111 -1
00002 F 02222 03333
00003 M 02222 03333
00004 F 04444 03333
00005 M 04444 05555
00006 F 04444 05555
00007 F 06666 07777
00008 M 06666 07777
00009 M 00001 00002
00010 M 00003 00006
00011 F 00005 00007
00012 F 00008 08888
00013 F 00009 00011
00014 M 00010 09999
00015 M 00010 09999
00016 M 10000 00012
00017 F -1 00012
00018 F 11000 00013
00019 F 11100 00018
00020 F 00015 11110
00021 M 11100 00020
00022 M 00016 -1
00023 M 10012 00017
00024 M 00022 10013
4
00021 00024
00019 00024
00011 00012
00022 00018

22 16 12 08
1  2  3   4     5
18 13 09  01 02 01111 02222 03333
      11  05 07
*/

