#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<string>stras;
int backvalue[100005];
void backvaluetable(string pattern){
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
	for(int i=pattern.size();i>0;i--){
		backvalue[i]=backvalue[i-1];
	}
	backvalue[0]=-1;
}
int kmpsearch(string pattern,string text){
	int i=0,j=0;
	while(i<text.size()){
		if(j==pattern.size()-1&&text[i]==pattern[j]){
			return 1;
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
	return 0;
}
int main(){
	char ch;
	string stra;
	string strb;
	while(true){
		ch=getchar();
		if(ch=='\n') {if(!stra.empty())stras.push_back(stra);break;}
		else if(ch>='a'&&ch<='z'){
			stra+=ch;
		}else if(ch>='A'&&ch<='Z'){
			stra+=ch+32;
		}else{
			if(!stra.empty())stras.push_back(stra);
			stra.clear();
		}
	}
	cin>>strb;
	backvaluetable(strb);
	for(int i=0;i<strb.size();i++){
		if(strb[i]>='A'&&strb[i]<='Z') strb[i]+=32;
	}
	int sum=0;
	for(int i=0;i<stras.size();i++){
		sum+=kmpsearch(strb,stras[i]);
	}
	cout << sum << endl;
	return 0;
}