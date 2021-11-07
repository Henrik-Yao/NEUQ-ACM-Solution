#include<bits/stdc++.h>
using namespace std;
int main()
{   bool c[10010]; 
	int a,b;
	while(cin>>a>>b)
 { memset(c,1,sizeof(c));
	
	for(int i=2;i<=b;i++)
	{ if(c[i]){
		for(int j=i*i;j<=b;j+=i){
			c[j]=false;
		}
	}
		
	}
	int flag=1;
	for(int i=a;i<=b;i++){
		if(c[i])
		{
			if(flag==1)
			{
			cout<<i;
			flag=0;
		    }
		    else cout<<" "<<i;
		}
	}
	
	cout<<endl;
 } 


}
