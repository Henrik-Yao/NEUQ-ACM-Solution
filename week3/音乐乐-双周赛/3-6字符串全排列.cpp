#include<bits/stdc++.h> 
using namespace std;

int main()
{
	char ch[9];
	int i,j;
	
	cin>>ch;
	int len=strlen(ch);
	sort(ch,ch+len);
	int num=1;
	for(i=1;i<=len;i++)
	num*=i;
	for(i=0;i<len;i++)
	cout<<ch[i];
	cout<<endl;
	for(i=j;j<=num-1;j++)
	{
		next_permutation(ch,ch+len);
		for(i=0;i<len;i++)
		cout<<ch[i];
		cout<<endl;
	}
	return 0;
}
