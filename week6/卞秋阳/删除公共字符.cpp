#include<bits/stdc++.h>
#include<string>
#include<map>
using namespace std;
string a[100000];
string b[100000];
int flag[100000];
int m,n,l; 
char c,h;
string q;
int main()
{ 
 int k=0;
while(c=getchar()){
		if(c=='\n') break;
		if(c>='a'&&c<='z') a[k]+=c;
		else if(c>='A'&&c<='Z') a[k]+=c;
		else if(c=='.') a[k]+=c; 
		else if(a[k]=="\0") continue;
		else k++;
	}
	int u=0;
	while(cin>>h){
		if(h=='\n') break;
		if(h>='a'&&h<='z')
		{b[u]+=h;
		n=h;
		 flag[n]=1;
		 } 
		else if(h>='A'&&h<='Z')
		{
			b[u]+=h;
			n=h;
			flag[n]=1;
		}
		else if(h=='.'){
		a[k]+=h;
		n=h;
		flag[h]=1;
	}
	else if(b[u]=="\0") continue;
		else u++;
	}
	

for(int j=0;j<=k;j++) 
{
	q=a[j];
	for(int e=0;e<q.length();e++)
	{   l=q[e];
		if(flag[l]!=1) cout<<q[e];
	}
    if(j!=k) cout<<" ";

}
}
