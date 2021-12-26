#include <bits/stdc++.h>
using namespace std;
char a[123456];

int trans(int i)
{
	int n=i+1;
	if(a[i]<='z' && a[i]>='a') cout<<a[i];
	else if(a[i]=='A') cout<<"sae";
	else if(a[i]=='B')	cout<<"tsaedsae";
	else if(a[i]=='(')
	{
		char c=a[i+1];
		int j=i;
		while(a[j]!=')')	j++;
		n=j+1;
		for(j--;j>i+1;j--)	
		{
			cout<<c;
        	trans(j);
		}
		cout<<c;
	}
	return n;
}
int main()
{
	cin>>a;
	int n,m=0;
	n=strlen(a);
	while(n-m)	m=trans(m);
	cout<<endl;
	return 0;
}
