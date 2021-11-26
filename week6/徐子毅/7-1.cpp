#include <iostream>
#include <string>
#include <vector>
using namespace std;
string pattern,text;
int findcatch=0;
int backvalue[100005];
void getbackvaluetable(string pattern){
	int ins = 0;
	for (int i = 1; i < pattern.size(); i++){
		if (pattern[i] == pattern[ins]){
			ins++;
			backvalue[i] = ins;
		}
		else{
			if (ins > 1)
				ins = backvalue[ins - 1];
			backvalue[i] = ins;
		}
	}
}
void movetable(int n){
	for(int i=n;i>0;i--){
		backvalue[i]=backvalue[i-1];
	}
	backvalue[0]=-1;
}
void kmpsearch(string pattern,string text){
	getbackvaluetable(pattern);
	movetable(pattern.size());
	int i=0,j=0;
	while(i<text.size()){
		if(j==pattern.size()-1&&text[i]==pattern[j]){
			findcatch++;
			j=backvalue[j];
		}
		if(text[i]==pattern[j]){
			i++;j++;
		}
		else{
			j=backvalue[j];
			if(j==-1){
				i++;j++;
			}
		}
	}
}
int main(){
	cin >> text;
	cin >> pattern;
	kmpsearch(pattern,text);
	cout << findcatch << endl;
	return 0;
}