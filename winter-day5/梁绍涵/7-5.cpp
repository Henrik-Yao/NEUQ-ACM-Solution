#include<bits/stdc++.h>
using namespace std;
struct dot{
	int sex;
	string father;
};
map<string,dot>mp;
string fname,lname;
int judge(string s1,string s2){
	int i=1,j;
	for( string A=s1; !A.empty(); i++,A=mp[A].father ){
		j=1;
		for( string B=s2; !B.empty(); j++,B=mp[B].father ){
			if(i>=5&&j>=5) return 1;
			if(A==B&&(i<5||j<5)) return 0;
		}
	}
	return 1;
}
int main(){
	int n,m;scanf("%d",&n);
	for( int i=0; i<n; i++ ){
		cin>>fname>>lname;
		if(lname.back()=='m') mp[fname].sex=1;
		else if(lname.back()=='f') mp[fname].sex=-1;
		else if(lname.back()=='n'){
			string buf=lname.substr(0,lname.length()-4);
			mp[fname]={1,buf};
		}
		else if(lname.back()=='r'){
			string buf=lname.substr(0,lname.length()-7);
			mp[fname]={-1,buf};
		}
	}
	scanf("%d",&m);
	for( int i=0; i<m; i++ ){
		string f1,l1,f2,l2;
		cin>>f1>>l1>>f2>>l2;
		if(mp.find(f1)==mp.end()||mp.find(f2)==mp.end()) printf("NA\n"); 
		else if(mp[f1].sex==mp[f2].sex) printf("Whatever\n");
		else printf("%s\n",judge(f1,f2)?"Yes":"No");
	}
	return 0;
}
