#include<bits/stdc++.h>
using namespace std;
int flag=0;
struct Node {
string ys;
string fyh;
};
Node node[10001];
int main(){
	int m,n;
	cin>>n>>m;
	string a;
	for(int i=0;i<n;i++){
		cin>>node[i].ys>>node[i].fyh;
	}
	for(int i=0;i<m;i++){
		flag=0;
		cin>>a;
		for(int i=0;i<n;i++){
			if(a==node[i].fyh){
			cout<<node[i].ys<<endl;
			flag=1;
			break;
		}
	}
		if(flag==0) cout<<"eh"<<endl;
	}
}
