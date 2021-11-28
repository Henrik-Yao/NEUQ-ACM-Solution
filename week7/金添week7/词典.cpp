#include <bits/stdc++.h>
using namespace std;
map<string,string>word;
int N,M;
int main()
{
	cin>>N>>M;
	for(int i=0;i<N;i++)
	{
		string string1,string2;
		cin>>string1>>string2;
		word[string2]=string1;
	}
	for(int i=0;i<M;i++)
	{
		string remp;
		cin>>remp;
		if(word.count(remp))
		cout<<word[remp];
		else
		cout<<"eh";
		if(i!=M-1)
		cout<<endl;
	}
	return 0;
}
