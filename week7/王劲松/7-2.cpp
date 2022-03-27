#include<bits/stdc++.h>
using namespace std;
int f(int i);
//int maxn=0;
string s0,ss;
int main(){
	int n,iii;
	cin>>s0;
	n=s0.size();
	for(iii=0;iii<n;iii++){
		if(s0[iii]!='[')ss+=s0[iii];
		else iii=f(iii);//iii=maxn;a
	}
	cout<<ss;
	return 0;
}
int f(int i){
	int nn,maxn=0;
	//string sss;
	if(s0[i+1]>'0'&&s0[i+1]<='9'&&s0[i+2]>='0'&&s0[i+2]<='9')nn=(s0[i+1]-'0')*10+s0[i+2]-'0',i+=3;
	else nn=s0[i+1]-'0',i+=2;
	while(nn--){
		for(int ii=i;;ii++){
			if(s0[ii]==']'){
				maxn=max(maxn,ii);
				//if(nn==0)return maxn;
				break;
			}
			else if(s0[ii]=='['){
				ii=f(ii);
			}
			else ss+=s0[ii];
		}
	}
	return maxn;
}
