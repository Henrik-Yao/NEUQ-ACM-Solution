#include<bits/stdc++.h>
using namespace std;
struct student
{
	string name;
	int score;
}stu[200];
bool cmp(student a,student b)
{
	if(a.score>b.score)
	return 1;
	else if(a.score==b.score)
	{
		return a.name<b.name;
	}
	else return 0;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>stu[i].name>>stu[i].score;
	}
	sort(stu,stu+n,cmp);
	for(int i=0;i<n-1;i++)
		{
			cout<<stu[i].name<<" "<<stu[i].score;
			cout<<endl;
		}
	cout<<stu[n-1].name<<" "<<stu[n-1].score;
}
