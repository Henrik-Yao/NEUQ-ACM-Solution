#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
vector<string>mode;
void getNext(int l,string a,int *next){
    next[0]=-1;
    int k=-1,i=0;
    while(i<l){
        if(k==-1||a[i]==a[k]){
            i++;k++;
            next[i]=k;
        }
        else k=next[k];
    }
}
bool KMP(string T,string P,int *b){
    int i=0,j=0;
    int len1=T.length();
    int len2=P.length();
    while(i<len1&&j<len2){
        if(j==-1||T[i]==P[j])
        {
            i++;j++;
            if(j==len2) return true;
        }
        else j=b[j];
    }
    return false;
}
int main(){
    string a,s;
    getline(cin,a);
    getline(cin,s);
    int len=a.length();
    int len1=s.length();
    for(int i=0;i<len1;i++)
    if(s[i]>='A'&&s[i]<='Z') s[i]+=32;
    string b="";
    int flag=0;
    for(int i=0;i<len;i++){
    	if(a[i]>='A'&&a[i]<='Z') {
    		b+=a[i]+32;
            if(flag) flag=0;
		}
		else if(a[i]>='a'&&a[i]<='z'){
			b+=a[i];
            if(flag) flag=0;
		}
		else {
			if(!flag) {
                mode.push_back(b);
			    b="";
                flag=1;
            }
		}
	}
    if(b!="") mode.push_back(b);
	int ans=0;
	int next[10001];
	getNext(len1,s,next);
	while(!mode.empty()){
		string c=mode.back();
		mode.pop_back();
		if(KMP(c,s,next)) ans++;
	}
	cout<<ans;
	return 0;
}
