#include <bits/stdc++.h>
using namespace std;
typedef struct 
{
	string name;
	int num;
}Stu;
Stu stu[21];
int main()
{
	int n,m,i,j,k,t;
	string str;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>str>>t;
		stu[i].num=t;
		stu[i].name=str;
		for(j=i-1;j>=0;j--)
		{
			if(stu[j].num>t || (stu[j].num==t && stu[j].name<str))
			{
				stu[j+1].num=stu[j].num;
				stu[j].num=t;
				stu[j+1].name=stu[j].name;
				stu[j].name=str;
			}
		}
		
	}
	while(i--)
	{
		cout<<stu[i].name<<' '<<stu[i].num;
		if(i)	cout<<endl;
	}
}
