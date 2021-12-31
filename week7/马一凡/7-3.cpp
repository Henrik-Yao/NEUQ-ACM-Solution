#include<iostream>
using namespace std;

int main(){
	string ss,cc;
	while(getline(cin, ss) && getline(cin, cc)){
	
	int hash[256] = {0};
	for(int i=0; i<cc.size(); i++){
		hash[cc[i]]++;
	}
	string r;
	for(int i=0; i<ss.size(); i++){
		if(hash[ss[i]] == 0){
			r = r+ss[i];
		}
	}
	cout << r << endl;
}
	return 0;
	
}
