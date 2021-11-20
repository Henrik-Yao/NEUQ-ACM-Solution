#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int sl,pl,Next[maxn],cnt;
char s[maxn],p[maxn];
void kmp() {
	for(int i=1,j=0;i<=sl;i++) {
		while(j&&s[i]!=p[j+1]) j=Next[j];
		if(s[i]==p[j+1]) j++;
		if(j==pl) {
			j=Next[j];
			cnt++;
		}
	}
}
int main() {
	cin>>s+1>>p+1;
	sl=strlen(s+1);
	pl=strlen(p+1); 
	for(int i=2,j=0; i<=pl; i++) {
		while(j&&p[i]!=p[j+1]) j=Next[j];
		if(p[i]==p[j+1]) j++;
		Next[i]=j;
	}
	kmp();
	cout<<cnt<<endl;
	return 0;
}


