#include<bits/stdc++.h>
using namespace std;
int main()
{
	char t;
	while((scanf("%c",&t))!=EOF)
	{
	string a1,c;
	getline(cin,a1);
	string y;
	y+=t;
	a1.insert(0,y);
	getline(cin,c);
	int e=a1.length();
	int r=c.length();
	int i,j;
	for(i=0;i<e-1;i++)
	for(j=0;j<r-1;j++)
	if(a1[i]==c[j]) 
	{
		a1.erase(i,1);
		i--;
		break;
	}
	cout<<a1<<'\n';
	continue;
	}
	return 0;
	
}