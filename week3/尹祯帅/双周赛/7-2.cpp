#include<bits/stdc++.h>
using namespace std;
void hnt(int q,string a,string b,string c)
{
	if(q==1) cout<<a<<"->"<<c<<endl;
	else 
	{
		hnt(q-1,a,c,b);
		cout<<a<<"->"<<c<<endl;
		hnt(q-1,b,a,c);
		
	}
 } 
 int main()
 {
 	int q;
 	string a,b,c;
 	cin>>q;
 	cin>>a>>b>>c;
	 hnt(q,a,b,c); 
 	return 0;
 }
