#include <bits/stdc++.h>
using namespace std;
map<string,string>eng;
int main(){
int n,m;
string s1,s2,s3;
cin>>n>>m;
while(n--){
	cin>>s1>>s2;
	eng[s2]=s1;
}
while(m--){
	cin>>s3;
	if(eng[s3]=="") cout<<"eh"<<endl;
	else cout<<eng[s3]<<endl;
}

return 0;

}
