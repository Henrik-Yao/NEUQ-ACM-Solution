#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> origin;
vector<int> odds;
vector<int> even;
int main(){
	int n;
	while(cin>>n){
		origin.push_back(n);
	}
	sort(origin.begin(),origin.end());
	bool first=true;
	for(int i=0;i<origin.size();i++){
		if(origin[i]%2==0) even.push_back(origin[i]);
		else odds.push_back(origin[i]);
		if(first) {cout << origin[i];first=false;}
		else cout << "->" << origin[i];
	}
	cout << endl;
	first=true;
	for(int i=0;i<odds.size();i++){
		if(first) {cout << odds[i];first=false;}
		else cout << "->" << odds[i];
	}
	cout << endl;
	first=true;
	for(int i=0;i<even.size();i++){
		if(first) {cout << even[i];first=false;}
		else cout << "->" << even[i];
	}
}