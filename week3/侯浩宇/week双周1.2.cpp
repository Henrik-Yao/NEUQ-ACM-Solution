#include<bits/stdc++.h>
using namespace std;
void move(string a,int n,string c){
  	cout<<a<<"->"<<c<<endl;
} 
void hanoi(int n,string a,string b,string c){
  	
  	if(n==1)
  	move(a,1,c);
  	else
  	{
  		hanoi(n-1,a,c,b);
  		move(a,n,c);
  		hanoi(n-1,b,a,c); 
	  }
}
int main(void){
  	int n;
  	string p[3];
  	cin>>n;
  	for(int i=0;i<3;i++)
  	cin>>p[i];
//  	cout<<p[2];
	hanoi(n,p[0],p[1],p[2]);
	return 0;
}
