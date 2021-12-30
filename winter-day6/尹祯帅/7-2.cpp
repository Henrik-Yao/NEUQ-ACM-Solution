#include<bits/stdc++.h>
using namespace std;
struct stu
{
	char *name;
	int goal;
	friend bool operator < (stu a1,stu a2){
        int b1=a1.goal,b2=a2.goal;
		if(b1>b2) 
        {
            return 1;
        }
        else if(b1<b2) return 0;
		else
		{
			if(strcmp(a1.name,a2.name)>0) return 0;
            else return 1;
		}
	}
};
int main()
{
	int n;
	cin>>n;
	stu a[n];
	for(int i=0;i<n;i++) 
	{
		a[i].name =new char;
		cin>>a[i].name>>a[i].goal;
	}
	sort(a,a+n);
	for(int i=0;i<n;i++) cout<<a[i].name<<' '<<a[i].goal<<'\n';
	return 0;
} 
