#include<iostream>
using namespace std;
string a,b,c;int n;
int h(int n,string a,string b,string c)
{
	if(n==1){
		cout<<a<<"->"<<c<<endl;
	}
	else{
		h(n-1,a,c,b);
		cout<<a<<"->"<<c<<endl;
		h(n-1,b,a,c);
	}
}
int main(){
	cin>>n>>a>>b>>c;
	h(n,a,b,c);
	
	
} 
