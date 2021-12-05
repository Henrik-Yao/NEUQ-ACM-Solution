#include <iostream>
using namespace std;
string unpack(string str){
	bool isclean=true;
	int i=0,j;
	for(i=0;i<str.size();i++){
		if(str[i]=='['){
			isclean=false;
			break;
		}
	}
	if(isclean){
		int doublestatus=1;
		string newstr="",cutstr="";
		if(str[0]>='0'&&str[0]<='9'){
			if(str[1]>='0'&&str[1]<='9'){
				doublestatus=((int)(str[0]-'0'))*10+(int)(str[1]-'0');
				for(int a=2;a<str.size();a++) cutstr+=str[a];
				for(int a=1;a<=doublestatus;a++) newstr+=cutstr;
				return newstr;
			}else{
				doublestatus=(int)(str[0]-'0');
				for(int a=1;a<str.size();a++) cutstr+=str[a];
				for(int a=1;a<=doublestatus;a++) newstr+=cutstr;
				return newstr;
			}
		}else return str;
	}else{
		string newstr="",shouldunpackstr="";
		for(int p=0;p<str.size();p++){
			int intoleft=0;
			shouldunpackstr="";
			if(str[p]!='[') newstr+=str[p];
			else if(str[p]=='['){
				intoleft=1;
				for(j=p+1;j<str.size();j++){
					if(str[j]=='[') intoleft++;
					if(str[j]==']') intoleft--;
					if(str[j]==']'&&intoleft==0) break;
					shouldunpackstr+=str[j];
				}
				newstr+=unpack(shouldunpackstr);
				p=j;
			}
		}
		return unpack(newstr);
	}
}
int main(){
	string strori;
	cin >> strori;
	cout << unpack(strori) << endl;
	return 0;
}