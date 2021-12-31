#include<bits/stdc++.h>
using namespace std;
char c[9];
bool f[9];
char b[9];
void qpl (char c[],char b[],bool f[],int right,int left)
{
	if(right==left)
	{
		for(int i=0;i<left;i++)
		{
			cout<<b[i];
		}
		cout<<'\n';
	}
	else
	for(int i=0;i<left;i++)
	{
		if(f[i]) continue;
		f[i]=1;
		b[right]=c[i];
		qpl(c,b,f,right+1,left);
		f[i]=0;
	}
}
int main()
{	
	
	cin>>c;
	int size=0,i=0;
	while(c[i])
	{
		size++;
		i++;
	}
	sort(c,c+size);
	qpl(c,b,f,0,size);
	return 0;
}
