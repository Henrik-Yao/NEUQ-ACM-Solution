#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int nextt[1000];
int cnt=0;
void ss(int a,int b);
int main(){
	char s0;
	getline(cin,s1);
	int j,k,i=0;
	int n=s1.length();
	for(i=0;i<n;i++){
		if(s1[i]>='A'&&s1[i]<='Z')s1[i]+='a'-'A';
	}
	cin>>s2;
	for(k=0;k<s2.size();k++){
		if(s2[k]>='A'&&s2[k]<='Z')s2[k]=s2[k]+'a'-'A';
	}
	nextt[0]=-1;
	for(j=0,k=-1;j<s2.size()-1;){
		if(k==-1||s2[j]==s2[k])nextt[++j]=++k; 
		else k=nextt[k]; 					 
	}
	int tou=0,wei=0;
	while(tou<=wei&&wei<n){
		while(s1[wei+1]<='z'&&s1[wei+1]>='a')wei++;
		ss(tou,wei);
		
		while(!(s1[wei+1]<='z'&&s1[wei+1]>='a')){
			if(s1[wei+1]=='\0')break;
			wei++;
		}
		wei++,tou=wei;
	}
	cout<<cnt;
	return 0;
}
void ss(int a,int b){
	if(b-a+1<s2.size())return;
	int mm=0;
	for(;a<=b;){
		if(s1[a]==s2[mm]){
			if(mm==s2.size()-1){
				cnt++;
				return;
			}
			mm++,a++;
		}
		else if(nextt[mm]==-1)mm=0,a++;
		else mm=nextt[mm];
	}
}
