#include<bits/stdc++.h>  
using namespace std;
void move(int n,string a,string b,string c)
{
	if(n==1){
		cout<<a<<"->"<<c<<endl;
	}
	else if(n==2){
		cout<<a<<"->"<<b<<endl;;
		cout<<a<<"->"<<c<<endl;;
		cout<<b<<"->"<<c<<endl;;
	}
	else{
		move(n-1,a,c,b);
		cout<<a<<"->"<<c<<endl;;
		move(n-1,b,a,c);
	}
}
int main(){
	int n;
    string a,b,c;
	cin>>n>>a>>b>>c;
	move(n,a,b,c);
	return 0;
}
