#include<iostream>
#include<cstring>
#include<map>
using namespace std;
struct MM{
	string c; 
	string z;
	string m ; 
	string x;
};

int n;
MM mm[1100];
map<string,pair<string,string> > mp;

char ha(string s){ 
	int sum=0;
	int len = s.length();
	for(int i=0; i<len; i++){
		if(s[i] >= 'A' && s[i] <= 'Z') s[i]=s[i]|32;
		if(s[i] >= '0' && s[i] <= '9') sum+=s[i]-'0';
		else sum+=s[i]-'a'+10;
	}
	
	sum = sum%36;
	
	if(sum < 10) return (sum+'0');
	else return (sum-10+'a');
}

string Hash(string s){ 
	string hh="0000";
	int len = s.length();
	
	int d[5]={0};
	
	for(int i=0; i < len%4; i++){
		d[i]++;
	}
	int j=0;
	for(int i=0; i<4; i++){
		d[i] = d[i]+len/4;
		string str=s.substr(j,d[i]);
		
		j = j+d[i];
		char h = ha(str);
		hh[i]=h;
	}
	return hh;
}

int main(void){
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin>> mm[i].c >> mm[i].z >> mm[i].m;
		mm[i].x = Hash(mm[i].m);
		
		if(mm[i].c == "R"){
			if(mp.find(mm[i].z) != mp.end()) 
				cout << "Repeated!" << endl;
			else {
				mp[mm[i].z].first = mm[i].m;
				mp[mm[i].z].second = mm[i].x;
				cout << "Signed!" << endl;
			}
		}
		else if(mm[i].c == "L"){
			if(mp.find(mm[i].z) == mp.end()){
				cout << "Failed!" << endl;
			}
			else{
				if(mp.find(mm[i].z)->second.first == mm[i].m) 
					cout << "Success!" << endl;
				else{
					if(mp.find(mm[i].z)->second.second == mm[i].x) 
						cout << "Attention!" << endl;
					else cout << "Failed!" << endl;
				}
			}
		}
	}		
	return 0;
} 


