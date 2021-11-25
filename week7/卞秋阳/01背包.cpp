#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[410][1510];
int v[500];
int w[500];
int m,n,va=0;
int main(){
    while(cin>>n>>m)
    {
    	for(int k=1;k<=n;k++)
    	{cin>>w[k];
		}
		for(int k=1;k<=n;k++)
    	{cin>>v[k];
		}
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(j>=w[i])
                a[i][j]=max(a[i-1][j],a[i-1][j-w[i]]+v[i]);
 
 
            else
                a[i][j]=a[i-1][j];
                
        }
        
    }
     for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
        	va=max(va,a[i][j]);
        }
    }
 
    
        cout<<va<<endl;
        va=0;
    }
 
 
    return 0;
    }


