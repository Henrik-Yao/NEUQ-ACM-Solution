#include<bits/stdc++.h>
using namespace std;
int n;
string s[10];
int pan(int x,int y){
	if(x!=1&&y!=1)return 1;
	if(x!=2&&y!=2)return 2;
	if(x!=3&&y!=3)return 3;
}
void huan(int n,int x,int y){
	int z=pan(x,y);
	if(n==2){
		cout<<s[x]<<"->"<<s[z]<<endl;
		cout<<s[x]<<"->"<<s[y]<<endl;
		cout<<s[z]<<"->"<<s[y]<<endl;
	}
	else if(n>2){
		huan(n-1,x,z);
		cout<<s[x]<<"->"<<s[y]<<endl;
		huan(n-1,z,y);
	}
}
int main(){
	cin>>n>>s[1]>>s[2]>>s[3];
	huan(n,1,3);
	return 0;
}
