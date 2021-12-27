#include <iostream>
using namespace std;
int top=0,ennd=0;
int sum=0;
string s;
int main() {
	while(cin>>s){
	int len = s.size();
	for (int i=0; i<len;i++) 
	{
		if (s[i]=='(') 
		{
			top++;
		}
		else
		{
			if (top == 0) 
			{
				ennd++;
			}
			else 
			{
				top--;
			}
		}
	}
	if (top==0&&ennd==0) 
	{
		cout << "Match"<<endl;
	}
	else {
		sum=ennd+top;
		cout <<sum<<endl;
		for(int i=0;i<ennd;i++)
		{
			cout << '(';
		}
        
		cout << s;
        for(int i = 0; i < top; i++)
        {
        	cout << ')';
		}
		cout<<endl;
            
	}
	top=0;ennd=0;
}
}

