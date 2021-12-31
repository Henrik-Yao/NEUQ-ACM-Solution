#include<bits/stdc++.h>
const int maxn=1000010;
using namespace std;
int i,j,m,n,ans=0;
char a[maxn];
char b[maxn];
int next1[maxn];
void f()
{
	int t=0;next1[0]=-1;int y=-1;
	while(t<n)
	{
		if(y==-1||b[t]==b[y])
		{
			t++;y++;next1[t]=y;
		}
		else y=next1[y];
	}
}
int Kmp(){
 	i=0;
 	j=0;
 	while(i<=m)
	 {   
 		
 		if(j==-1||a[i]==b[j])
		 {
 			i++;
			 j++;
		 }
		 else
		 {
		 j=next1[j];
         }
         if(j==n) {
		 ans++;
		 }
	 }
	 return ans;	
}

int main()
{ 
	cin>>a;
	cin>>b;
	 m=strlen(a);
	 n=strlen(b);
	 f();
	Kmp();
	cout<<ans;
	
} 
