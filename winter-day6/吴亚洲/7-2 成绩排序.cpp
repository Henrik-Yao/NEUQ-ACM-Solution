#include<bits/stdc++.h>
using namespace std;
struct Stu
{
	string name;
	int score;
}stu[25];
bool cmp(Stu a,Stu b)
{
	if(a.score>b.score||(a.score==b.score&&a.name<b.name))
	return true;
	else
	return false;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>stu[i].name>>stu[i].score;
	sort(stu+1,stu+n+1,cmp);
	for(int i=1;i<=n;i++)
	cout<<stu[i].name<<" "<<stu[i].score<<endl;
}
