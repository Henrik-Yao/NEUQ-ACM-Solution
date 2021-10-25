#include<iostream>
using namespace std;
struct club {
	int flag;
	string name;
	bool yj=0; 
} club1[100001];
int main()
{
int n,m,t1,t2,lc;
	cin>>n>>m;
	lc=0;
	for (int i=0;i<n;i++)
	{
		cin>>club1[i].flag;
		cin>>club1[i].name;
	 } 
	 for (int i=0;i<m;i++)
	 {
	 	cin>>t1>>t2;
	 	if (t2>n)
	 	t2=t2%n;
	 	if (t1==0&&club1[lc].flag==0)
	 	{
	 		club1[lc].yj=0;
	 		if (lc<t2)
	 		{
	 		lc=n-(t2-lc);
	 	}
	 		else
	 		lc-=t2; 
	 		club1[lc].yj=1;
		 }
		 else if (t1==1&&club1[lc].flag==1)
	 	{
	 		club1[lc].yj=0;
	 		if (lc<t2)
	 		{
	 		lc=n-(t2-lc);
	 	}
	 		else
	 		lc-=t2; 
	 		club1[lc].yj=1;
		 }
		 else if (t1==0&&club1[lc].flag==1)
	 	{
	 		club1[lc].yj=0;
	 		if (lc+t2>n)
	 		{
	 		
	 		lc=(lc+t2)%n;
	 	}
		 else
	 		lc+=t2; 
	 		club1[lc].yj=1;
		 }
		 else if (t1==1&&club1[lc].flag==0)
	 	{
	 		club1[lc].yj=0;
	 		if (lc+t2>n)
	 		{
	 		lc=(lc+t2)%n;
	 	}
	 		else
	 		lc+=t2; 
	 		club1[lc].yj=1;
		 }
	 }
	 for (int i=0;i<n;i++)
	 if (club1[i].yj==1)
	 cout<<club1[i].name;
	 return 0;
}