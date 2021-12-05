#include<iostream>
#include<map>
using namespace std;

map<string, string>mp;
map<string, string>::iterator aa;

int main(){
	int n,m;
	cin >> n >> m;
	string cc,ss,ll;
	for(int i=0; i<n; i++){
		cin >> cc >> ss;
		mp[ss] = cc;
	}
	for(int i=0; i<m; i++){
		cin >> ll;
		aa = mp.find(ll);
		if(aa == mp.end()){
			cout << "eh" << endl;
		}
		else{
			cout << mp[ll] << endl;
		}
	}
	
	
	
	return 0;
} 
