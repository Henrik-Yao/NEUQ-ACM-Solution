#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string A[1000], B;
int main()
{
	int now=0;
	char ty;
	scanf("%c", &ty);
	while(ty!='\n')
	{
		if((ty<'a')||(ty>'z'))
		if((ty<'A')||(ty>'Z'))
		if(A[now]!="\0")
		{
			now+=1;
			scanf("%c", &ty);
			continue;
		}
		else
		{
			scanf("%c", &ty);
			continue;
		}
		if(ty>='A'&&ty<='Z')	ty+='a'-'A';
		A[now]+=ty;
		scanf("%c", &ty);
	}
	cin>>B;
	for(int i=0; B[i]!='\0'; i++)	if(B[i]>='A'&&B[i]<='Z')	B[i]+='a'-'A';
	int total=0;
	for(int i=0; i<=now; i++)
	if(A[i].find_first_of(B))
	{
		total+=1;
	}
	cout<<total;
	return 0;
}
