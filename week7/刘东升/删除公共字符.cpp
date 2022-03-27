#include <bits/stdc++.h>
using namespace std;
string text,partten;
const int M=100001;
bool judge[M];
int main()
{
	while (getline(cin,text))
	{
		memset(judge,0,sizeof(judge));
		getline(cin,partten);
		for(int i=0;i<partten.size();i++)
		{
			judge[partten[i]-0]=true;
		}
		for(int i=0;i<text.size();i++)
		{
			if (!judge[text[i]])
			{
				cout<<text[i]; 
			}
		}
		cout << endl;
	}
}
