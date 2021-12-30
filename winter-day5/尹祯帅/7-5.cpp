#include<bits/stdc++.h>
using namespace std;
struct people{
	char sex;
	string father;
};
map<string,people> mp;
int panduan(string a,string b){
	int i = 1,j;
	for(string A = a;!A.empty();A = mp[A].father,i++){
		j = 1;
		for(string B = b;!B.empty();B = mp[B].father,j++){
			if(i >= 5&&j >= 5)
				return 1;
			if(A==B && (i<5||j<5))
				return 0;
		}
	}
	return 1;
}
int main(){
	int N;
	cin.sync_with_stdio(false);	
	cin >> N;
	string a,b;
	for(int i = 0;i < N;i++){
		cin >> a >> b;
		if(b.back() == 'r'){
			mp[a] = {'f',b.substr(0,b.size()-7)};
		}else if(b.back() == 'n') {
			mp[a] = {'m',b.substr(0,b.size()-4)};
		}else{
			mp[a].sex = b.back();
		}
	}
	int M;
	cin >> M;
	string str;
	for(int i = 0;i < M;i++){
		cin >> a >> str >> b >> str;
		if(mp.find(a) == mp.end() || mp.find(b) == mp.end())
			printf("NA\n");
		else if(mp[a].sex == mp[b].sex)
			printf("Whatever\n");
		else 
			printf("%s\n", panduan(a, b) ? "Yes" : "No");
        
	}return 0;
}
