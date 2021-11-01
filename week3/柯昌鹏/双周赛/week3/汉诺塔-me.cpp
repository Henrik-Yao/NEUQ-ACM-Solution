#include <iostream>
#include <string> 
using namespace std;
int han(int n,string a,string b,string c)
{
	if(n==1) cout<<a<<"->"<<c<<endl;
	else {
    han(n-1,a,c,b);
	cout<<a<<"->"<<c<<endl;
	han(n-1,b,a,c);	}
 } 
 int main ()
 {
 	int n;
 	string a[3];
 	cin>>n;
 	for(int i=0;i<3;i++) cin>>a[i];
 	han(n,a[0],a[1],a[2]);
 	return 0;
 	
 }
