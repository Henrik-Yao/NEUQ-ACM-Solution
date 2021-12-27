#include<iostream>
#include<set>
using namespace std;
set<int> s[10000];
int len=0;
int main(){
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		if(!s[len].count(a)&&!s[len].count(b)){
			len++;
			s[len].insert(a);
			s[len].insert(b);
		}
		else if(!s[len].count(a)){
			s[len].insert(a);
		}
		else if(!s[len].count(b)){
			s[len].insert(b);
		}
	}
	for(int i=0;i<q;i++){
		int c,d;
		cin>>c>>d;
		int flag=0;
	for(int i=1;i<=len;i++){
		if(s[i].count(c)&&s[i].count(d)){
			flag=1;
			break;
		}
	}
	if(flag) cout<<"In the same gang."<<endl;
	else cout<<"In different gangs."<<endl;
}
	cout<<len<<endl;
}
