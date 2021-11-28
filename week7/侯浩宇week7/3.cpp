#include<bits/stdc++.h>
using namespace std;
int m=0;
int ss(){
		 
		string a[10000],b[10000];
		bool p[10000];
		memset(p,1,10000);
		if(getline(cin,a[m])&&getline(cin,b[m])){
//		cin>>b[m];
		for(int i=0;i<b[m].length();i++)
		if(p[int(b[m][i])]) p[int(b[m][i])]=0;
		if(m)cout<<endl;
		m++;
//		if(m%2==1)
		for(int i=0;a[m-1][i];i++)
		if(p[int(a[m-1][i])])cout<<a[m-1][i];	
		
		return 1;		
		}
		else return 0;	
}
int main(){
	while(ss()){
	}
	return 0;
}
