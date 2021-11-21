#include<bits/stdc++.h> 
using namespace std;
const int M=1000001;
int ans=0;
int nexts[M];
string text,partten;
void next(string partten);
void search(string text,string partten);
int main()
{
	cin>>text>>partten;
	next(partten);
	search(text,partten);
	cout<<ans;
}
void next(string partten)
{
	int now=0;
	for(int i=1;i<partten.length();)
	{
		if(partten[now]==partten[i])
		{
			now++;
			nexts[i]=now;
			i++;
		}
		else if(now)
		{
			now = nexts[now - 1];
		}
		else
		{
			nexts[i]=now;
			i++;
		}
	}
}
void search(string text,string partten)
{
	int pos = 0;
	for(int i=0;i<text.length();)
	{
		if (text[i] == partten[pos])
		{
			i++;
			pos++;
		}
		else if(pos)
		{
			pos = nexts[pos - 1];
		}
		else
		{
			i++;
		}
		if (pos ==partten.length())
		{
			ans++;
			pos = nexts[pos - 1];
		}
	}
}
