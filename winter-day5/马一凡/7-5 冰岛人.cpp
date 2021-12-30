#include<bits/stdc++.h>
#include<iostream>
#include<cstring>

using namespace std;

struct people{
	char sex;
	string father;
};

map<string,people> mp;

int panduan(string a,string b){
	int i=1,j;
	for(string aa=a; !aa.empty(); aa = mp[aa].father,i++){
		j = 1;
		for(string bb=b; !bb.empty(); bb=mp[bb].father,j++){	//各自比较五代 
			if(i >= 5 && j >= 5)	//五代都没有，就可以交往 
				return 1;
			if(aa == bb && (i<5 || j<5))	//五代内出现相同祖先，不可交往 
				return 0;
		}
	}
	return 1;	//不够五代，且没有共同祖先，可交往 
}

int main(){
	int n;
	cin.sync_with_stdio(false);	//这句不能少，要不然运行超时
	cin >> n;
	string a,b;
	for(int i=0; i < n; i++){
		cin >> a >> b;
		if(b.back() == 'r'){	//维京女生 
			mp[a] = {'f',b.substr(0,b.size()-7)};	//父亲的名字是女生的姓，去掉"sdottir" 
		}
		else if(b.back() == 'n') {	//维京男生 
			mp[a] = {'m',b.substr(0,b.size()-4)};	//父亲的名字是男生的姓，去掉"sson" 
		}
		else{	//不是本地的，直接用最后一位判断性别，不需要知道父亲 
			mp[a].sex = b.back();
		}
	}
	
	int m;
	cin >> m;
	string str;
	for(int i=0; i < m; i++){
		cin >> a >> str >> b >> str;
		if(mp.find(a) == mp.end() || mp.find(b) == mp.end())	//找是否有一个不在名单里 
			printf("NA\n");
		else if(mp[a].sex == mp[b].sex)	//判断是否同性 
			printf("Whatever\n");
		else 
			printf("%s\n", panduan(a, b) ? "Yes" : "No");
	}
}

