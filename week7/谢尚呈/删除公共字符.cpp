#include<iostream>
#include<string>
using namespace std;

string a, b, c;

int main()
{
	int count=0;
	while(getline(cin, a))
	{
		if(count)	cout<<endl;
		else count+=1;
		getline(cin, b);
		for(string::iterator it=a.begin(); it!=a.end(); it++)
		{
			bool fit=true;
			for(string::iterator that=b.begin(); that!=b.end(); that++)
			if(*it==*that)
			{
				fit=false;
				break;
			}
			if(fit)	c.push_back(*it);
		}
		cout<<c;
		a.clear();
		b.clear();
		c.clear();
	}
	return 0;
}
