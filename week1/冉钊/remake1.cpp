#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main() {
	int n,number=0;
	string w,m;
	cin>>n>>w;
	int a=w.length();
	for(int i=1; i<=n; i++) {
		cin>>m;
		int b=m.length();
		for(int j=1; j<=a-b+1; j++) {
			string flag;
			flag.clear();
			for(int k=j; k<=j+b-1; k++) {

				flag+=w[k-1];
			}
			if(m==flag)
				number++;

		}
		cout<<number<<endl;
		number=0;
	}
	return 0;
}
