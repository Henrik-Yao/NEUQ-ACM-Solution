#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a,b;
	char c[1234567];
	int lena,lenb,i,j,k,t=0;
	while(getline(cin,a))
	{
		k=0;
		if(!a[0]) break;
		lena=a.length();
		getline(cin,b);
		lenb=b.length();
		for(i=0;i<lena;i++)
		{
			bool flag=1;
			for(j=0;j<lenb;j++)
				if(a[i]==b[j])
				{
					flag=0;
					break;
				}
			if(flag) 
			{
				c[k]=a[i];
				k++;
			}
		}
		if(t)		cout<<endl;
		else t++;
		for(i=0;i<k;i++)
		cout<<c[i];
	}
	return 0;
}
