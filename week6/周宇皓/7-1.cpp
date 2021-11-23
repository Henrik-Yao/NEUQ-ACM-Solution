#include<bits/stdc++.h>
using namespace std;
string a,b;
int nxt[10000001]; 
void getnext(){
	nxt[0]=-1;
	int i = 0,j=-1;
	while(i<a.size())
		{
			if(j==-1||a[i]==a[j])
			nxt[++i]=++j;
			else
			j = nxt[j];
		}
		return;
	}

int kmp(string s,string t){
	int c = 0;
	int i = 0,j = 0;
	while(i<s.length()){
		if(j==-1||s[i]==t[j]){
			i++;
			j++;
		}
		else
		j = nxt[j];
	
	if(j==t.length())
	c++;}
	return c;
}
int main(){
	cin>>b>>a;
	getnext();
	cout<<kmp(b,a);
} 
