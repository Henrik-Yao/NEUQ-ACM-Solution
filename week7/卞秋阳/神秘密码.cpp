#include<bits/stdc++.h>
using namespace std;
string begin();
int main()
{

cout<<begin();
	
} 


string begin()
{ int n;
  string mm="",mm1;
  char a;
  while(cin>>a)
  {
  	if(a=='[')
  	{
  		cin>>n;
  		mm1=begin();
  		while(n--) mm+=mm1;
	  }
	  
	  
	  else{
	  	if(a==']') return mm;
	  	else mm+=a;
	  }
  }
	
	
	
}



