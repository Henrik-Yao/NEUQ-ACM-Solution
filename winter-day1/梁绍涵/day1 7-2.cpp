#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a,ser,b;
	int now=0,len=0,mod=1;
	getline(cin,a);
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='a'&&a[i]<='z'||a[i]==' ')
		{
			string x;
			x=a[i];
			if(mod==1)
			{
				b.insert(now,x);
				now++;
				len++;
			}
			else
			{
				b[now]=a[i];now++;
//				cout<<a[i];
//				if(now!=len) continue;
				len++;
			}
//			cout<<b<<"?"<<endl;
		}
		if(a[i]=='[')
		{
			now=0;
		}
		if(a[i]==']')
		{
			now=len;
		}
		if(a[i]=='{')
		{
			if(now==0) continue;
			now--;
		}
		if(a[i]=='}')
		{
			if(now==len) continue;
			now++;
		}
		if(a[i]=='-')
		{
			if(mod==1)
			{
				mod=0;
				continue;
			}
			else
			{
				mod=1;
				continue;
			}
		}
		if(a[i]=='=')
		{
			b.erase(now-1,1);
			now--;
			len--;
		}
	}
	cout<<b;
}
