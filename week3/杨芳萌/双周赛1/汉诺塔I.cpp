#include<bits/stdc++.h>
#define str string
using namespace std;
int n;
string a,b,c;
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

void solve(int k, str a, str b, str c) {
	if(k==1) {
		cout<<a<<"->"<<c<<endl;
		return;
	}
	solve(k-1,a,c,b);
	cout<<a<<"->"<<c<<endl;
	solve(k-1,b,a,c);
	return;
}

int main(){
	read(n);
	cin>>a>>b>>c;
	solve(n,a,b,c);
    return 0;
}

