#include<bits/stdc++.h>
using namespace std;
void l();
void r();
map<string,int>rr;
map<string,string>rrmm;
void hx(string sss);
map<char,int>hxx;
char rc[4],checkk[4];
int main(){
	int n,i;
	cin>>n;
	for(char ch='a',i=10;ch<='z';ch++)hxx[ch]=i++;
	for(char ch='A',i=10;ch<='Z';ch++)hxx[ch]=i++;
	for(char ch='0',i=0;ch<='9';ch++)hxx[ch]=i++;
	for(i=0;i<n;i++){
		string s;
		cin>>s;
		if(s=="R")r();
		if(s=="L")l();
        if(i!=n-1)cout<<endl;
	}
	return 0;
}
void r(){
	string s1,s2;
	cin>>s1>>s2;
	if(rr[s1])cout<<"Repeated!";
	else rr[s1]=1,rrmm[s1]=s2,cout<<"Signed!";
}
void l(){
	string s1,s2;
	cin>>s1>>s2;
	if(!rr[s1]){
		cout<<"Failed!";
		return;
	}
	else if(s2==rrmm[s1]){
		cout<<"Success!";
		return;
	}
	else {
		hx(s2),strcpy(checkk,rc),hx(rrmm[s1]);
		if(checkk[0]==rc[0]&&checkk[1]==rc[1]&&checkk[2]==rc[2]&&checkk[3]==rc[3]){
			cout<<"Attention!";
			return;
		}
	}
	cout<<"Failed!";
}
void hx(string sss){
	int ns=sss.length();
	int n1,n2,n3,n4,n0;
	if(ns%4==0)n1=n2=n3=n4=ns/4;
	if((ns-1)%4==0)n2=n3=n4=n1=ns/4,n1++;
	if((ns-2)%4==0)n2=n3=n4=n1=ns/4,n1++,n2++;
	if((ns-3)%4==0)n2=n3=n4=n1=ns/4,n1++,n2++,n3++;
	int cn1=0,cn2=0,cn3=0,cn4=0;
	for(n0=0;n0<n1;n0++)cn1+=hxx[sss[n0]];
	for(;n0<n1+n2;n0++)cn2+=hxx[sss[n0]];
	for(;n0<n1+n2+n3;n0++)cn3+=hxx[sss[n0]];
	for(;n0<ns;n0++)cn4+=hxx[sss[n0]];
	cn1%=36,cn2%=36,cn3%=36,cn4%=36;
	if(cn1<=9)rc[0]='0'+cn1;
	else rc[0]='a'+cn1-10;
	if(cn2<=9)rc[1]='0'+cn2;
	else rc[1]='a'+cn2-10;
	if(cn3<=9)rc[2]='0'+cn3;
	else rc[2]='a'+cn3-10;
	if(cn4<=9)rc[3]='0'+cn4;
	else rc[3]='a'+cn4-10;
//	cout<<rc<<endl;
}
