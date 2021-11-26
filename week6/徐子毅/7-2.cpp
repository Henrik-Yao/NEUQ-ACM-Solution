#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int s1,s2,s3,s4;
struct users{
	string name;
	string passwd;
	string hash;
};
vector<users> usersdata;
void breakstring(int n){
	s1=s2=s3=s4=n/4;
	n=n-s1*4;
	if(n>0) {s1++;n--;}
	if(n>0) {s2++;n--;}
	if(n>0) {s3++;n--;}
	return;
}
int turn10(char n){
	if(n>='0'&&n<='9') return (int)(n-'0');
	else if(n>='a'&&n<='z') return (int)(n-'a')+10;
	else if(n>='A'&&n<='Z') return (int)(n-'A')+10;
}
char turn36(int n){
	if(n>=0&&n<=9) return (char)(n+'0');
	else if(n>=10&&n<=35) return (char)(n-10+'a');
	else return turn36(n-36);
}
string Hashing(string str){
	string num="0000";
	int bnum=0;
	if(str.size()<=4) return str;
	breakstring(str.size());
	int i=0;
	for(i=0;i<s1;i++){
		bnum+=turn10(str[i]);
	}
	num[0]=turn36(bnum);
	bnum=0;
	for(;i<s1+s2;i++){
		bnum+=turn10(str[i]);
	}
	num[1]=turn36(bnum);
	bnum=0;
	for(;i<s1+s2+s3;i++){
		bnum+=turn10(str[i]);
	}
	num[2]=turn36(bnum);
	bnum=0;
	for(;i<str.size();i++){
		bnum+=turn10(str[i]);
	}
	num[3]=turn36(bnum);
	return num;
}
int main(){
/* 	
	string str;
	cin >> str;
	cout << Hashing(str) << endl;
	 */
	int abc;
	cin >> abc;
	char operation;
	string name,password;
	bool repeated;
	for(int i=1;i<=abc;i++){
		cin >> operation;
		repeated=false;
		if(operation=='R'){
			cin >> name >> password;
			for(int i=0;i<usersdata.size();i++){
				if(name==usersdata[i].name){
					cout << "Repeated!" << endl;
					repeated=true;
					break;
				}
			}
			if(!repeated){
				users newuser;
				newuser.name=name;
				newuser.passwd=password;
				newuser.hash=Hashing(password);
				usersdata.push_back(newuser);
				cout << "Signed!" << endl;
			}
		}
	    if(operation=='L'){
			cin >> name >> password;
			users compareduser;
			for(int i=0;i<usersdata.size();i++){
				if(name==usersdata[i].name){
					compareduser=usersdata[i];
					break;
				}
			}
			if(password==compareduser.passwd){
				cout << "Success!" << endl;
			}
			else{
				if(Hashing(password)==compareduser.hash) cout << "Attention!" << endl;
				else cout << "Failed!" << endl;
			}
		}
	}
	return 0;
}