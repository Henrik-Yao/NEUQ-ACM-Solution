#include <iostream>
#include<algorithm>
#include<map>
using namespace std;
struct pp 
{
	char sex;
	string father;
};
map<string, pp> ma;
bool jud(string a, string b) 
{
	int i = 1, j;
	for (string aa = a; !aa.empty(); aa = ma[aa].father, i++) 
	{
		j = 1;
		for (string bb = b; !bb.empty(); bb = ma[bb].father, j++) 
		{
			if (i >= 5 && j >= 5)
				return 1;
			if (aa == bb && (i < 5 || j < 5))
				return 0;
		}
	}
	return 1;
}

int main() {
	int n;
	cin.sync_with_stdio(false);	//这句不能少，要不然运行超时
	cin >> n;
	string a, b;
	for (int i = 0; i < n; i++) 
	{
		cin >> a >> b;
		if (b.back() == 'r') 
		{	//维京女生 
			ma[a] = { 'f',b.substr(0,b.size() - 7) };	//父亲的名字是女生的姓，去掉"sdottir" 
		}
		else if (b.back() == 'n') {	//维京男生 
			ma[a] = { 'm',b.substr(0,b.size() - 4) };	//父亲的名字是男生的姓，去掉"sson" 
		}
		else {	//不是本地的，直接用最后一位判断性别，不需要知道父亲 
			ma[a].sex = b.back();
		}
	}

	int m;
	cin >> m;
	string str;
	for (int i = 0; i < m; i++) {
		cin >> a >> str >> b >> str;
		if (ma.find(a) == ma.end() || ma.find(b) == ma.end())	//找是否有一个不在名单里 
			printf("NA\n");
		else if (ma[a].sex == ma[b].sex)	//判断是否同性 
			printf("Whatever\n");
		else
			printf("%s\n", jud(a, b) ? "Yes" : "No");
	}
}
