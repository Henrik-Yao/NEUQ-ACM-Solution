#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	while(cin>>str)
	{
		int n=0, ans=0, l_s=str.size();
		for(int i=0; i<l_s; i++)
		{
			if(str[i]=='(')
				n++;
			else
				if(n!=0)
					n--;
				else
					ans++;
		}
		if((ans+n)==0)
			puts("Match");
		else
		{
			cout<<ans+n<<endl;
			for(int i=1; i<=ans; i++)
				cout<<'(';
			cout<<str;
			for(int i=1; i<=n; i++)
				cout<<')';
			cout<<endl;
		}
	}
	
	return 0;
}