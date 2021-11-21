#include<iostream>
#include<cstring>
using namespace std;

string ss,cc,ll;

int main(){
	
	getline(cin, ss);
//	getline(cin, cc);
	cin >> cc;
	
	for(int i=0; i<ss.length(); i++){
		if(ss[i] >= 'A' && ss[i] <= 'Z') 
			ss[i]+=32;
		if(!(ss[i] >= 'a' && ss[i] <= 'z')) 
			ss[i] = ' ';
	} 
//	cout << ss[i];

	for(int i=0; i<cc.length(); i++){
		if(cc[i] >= 'A' && cc[i] <= 'Z') 
			cc[i] += 32;
	}
	ss = " "+ss+" ";
//	cout << ss[i];


	for(int i=0; i<ss.length(); i++){
		if(ss[i] == ' ' && ss[i-1] == ' ') 
			continue;
		ll = ll+ss[i];
	}
	ss = ll;
	
	int t;
	t = ss.find(cc,0);
	int tt = 0;
	if(t == -1){
		cout << 0;
		return 0;
	}
	int sum = 0; 
	while(t != -1){
		sum++;
		tt = ss.find(' ',t);
		t = ss.find(cc,tt);
	}
	cout << sum;
	return 0;
	
	
	
}
