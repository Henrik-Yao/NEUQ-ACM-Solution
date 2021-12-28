#include <bits/stdc++.h>
using namespace std;
struct tu
{
	int a;
	int b;
	int w;
};
int main()
{
	int n,e;
	cin>>n>>e;
	tu Map[e];
	 for(int i=0;i<e;i++) cin>>Map[i].a>>Map[i].b>>Map[i].w;
	 for(int i=0;i<e;i++)
	 for(int j=i+1;j<e;j++)
     {
         if((Map[i].a)>(Map[j].a))
	{
		tu c=Map[i];
		Map[i]=Map[j];
		Map[j]=c;
	}
	else if(Map[i].a==Map[j].a)
	if((Map[i].b)>(Map[j].b))
	{
		tu c=Map[i];
		Map[i]=Map[j];
		Map[j]=c;
	}
     }
	 int y=0;
	 int k;
	 cin>>k;
	 while(k--)
	 {
	 	int a1,a2;
	 	cin>>a1>>a2;
	 	for(int i=0;i<e;i++)
	 	if(Map[i].a==a1&&Map[i].b==a2)
	 	{
	 		 Map[i].a=-1;
	 		 break;
		 }
	 }
	 for(int i=0;i<e;i++)
	 {
	 	while(Map[y].a==-1) y++;
	 	if(Map[y].a==i) 
		 {
		 	cout<<i<<":";
	 		while(Map[y].a==i||Map[y].a==-1)
	 		{
	 			if(Map[y].a!=-1) printf("(%d,%d,%d)",Map[y].a,Map[y].b,Map[y].w);
	 			y++;
			 }
			 cout<<'\n';
		 }
		 
	 }
	 
	return 0;
} 
