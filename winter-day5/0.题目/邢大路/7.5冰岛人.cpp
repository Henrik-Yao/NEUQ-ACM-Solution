#include<bits/stdc++.h>
using namespace std;
struct node{
	int sex;
	string root;
};
map<string,node>person;
int judge(string s1,string s2){
	int i=1;
	int j;
	for(string S1=s1;!S1.empty();i++,S1=person[S1].root){
		j=1;
		for(string S2=s2;!S2.empty();j++,S2=person[S2].root){
			if(i>=5&&j>=5)return 1;
			else if(S1==S2&&(i<5||j<5))return 0;
		}
	}
	return 1;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string fa,s;
		cin>>fa>>s;
		int len=s.size();
		if(s.back() =='m')person[fa].sex=1;
		else if(s.back() =='f')person[fa].sex=0;
		else if(s.back() =='n'){
			person[fa].sex=1;
			string s1=s.substr(0,len-4);
			person[fa].root=s1;
		}
		else if(s.back() =='r'){
			person[fa].sex=0;
			string s1=s.substr(0,len-7);
			person[fa].root=s1;
		}
	}
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		string f1,s1,f2,s2;
		cin>>f1>>s1>>f2>>s2;
		if(person.find(f1)==person.end()||person.find(f2)==person.end()){
			cout<<"NA"<<endl;
		}
		else if(person[f1].sex==person[f2].sex){
			cout<<"Whatever"<<endl;
		} 
		  else printf("%s\n",judge(f1,f2)?"Yes":"No");
	}
	return 0;
}
	
