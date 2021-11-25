#include<bits/stdc++.h>
using namespace std;
int main() {
	string t,p;
	while(getline(cin,t),getline(cin,p)){
		int tl=t.length();
		int pl=p.length();
		for(int i=0;i<pl;i++){
			int mid;
			while((mid=t.find(p[i]))!=-1){
				t.erase(mid,1);
			}
		}
		cout<<t<<endl;
	}
	return 0;
}


