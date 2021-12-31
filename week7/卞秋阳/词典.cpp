#include<bits/stdc++.h>
using namespace std;
string d;
int flag=0;
struct dc{
	string a;
	string b;
}c[10010];
int main()
{ int n,m;
cin>>n>>m;
    for(int i=1;i<=n;i++)
  {
  cin>>c[i].a>>c[i].b;
  }
	while(m--)
	{
		cin>>d;
		for(int i=1;i<=n;i++)
		{
			if(c[i].b==d)
			{
				cout<<c[i].a<<endl;
			    flag=1; 
			}
			
		}
		if(flag==0) cout<<"eh"<<endl;
		flag=0;
	}
	
	
	
	
 } 
