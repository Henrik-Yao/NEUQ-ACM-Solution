#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	bool jud;
	while(cin>>a>>b)
	{
        bool ju=1;
	for (;a<=b;a++)
	{
        
		jud=1;
		for(int i=2;i<=sqrt(a);i++) 
			if(a%i==0) 
			{
				jud=0;
				break;	
			} 
			if(jud==1&&ju==1) cout<<a,ju=0;
           else if(jud==1) cout<<' '<<a;
	} cout<<'\n';
	}
	return 0;
 } 

