#include<bits/stdc++.h>
using namespace std; 
int c,d,flag=0,g;
int a[110],b[110];
int main()
{
	while(cin>>c)
    {
        
    
	for(int i=0;i<c;i++)
	{
		cin>>a[i];
	}
	cin>>d;
	for(int i=0;i<d;i++)
	{
		cin>>b[i];
	}
	sort(a,a+c);
	for(int i=0;i<c-1;i++){
		cout<<a[i]<<" ";
	}
	cout<<a[c-1]<<endl;

	for(int i=0;i<d;i++)
	{
		for(int j=0;j<c;j++)
		{  
		
		if(b[i]==a[j]) 
		{   if(i!=0) cout<<" "; 
			cout<<j+1;flag++; 
		}
		
		}
		if(flag==0&&i==0) cout<<0;
		if(flag==0&&i!=0) cout<<" "<<0;
		flag=0;
        
		
	}
	cout<<endl;
    }
	
}
