#include<bits/stdc++.h>
using namespace std;
int v[100001];
int main()
{
	string s;
	stack<char>match;
	while(cin>>s)
	{
		int n=s.size(),n1=0,n2=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='(')
			{
				n1++;
				match.push(s[i]);
			}
			else
			{
				if(!match.empty()&&match.top()=='(')
				{
					n1--;
					n2++;//匹配成功
					match.pop();
				}
			}
		}
		while(!match.empty()) match.pop();
		n2=n-2*n2-n1;
		if(n1+n2==0)
		{
			cout<<"Match\n";
			continue;
		}
		else cout<<n1+n2<<endl;
		s.insert(n,n1,')');
		s.insert(0,n2,'(');
		cout<<s<<endl;
	}
	return 0;
}