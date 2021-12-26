#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,s2;
	getline(cin,s);
	int n=s.size();
	int j=-1,n2=0;
	int flag=1;
	for(int i=0;i<n;i++)//读s
	{
		if(s[i]=='[')//Home
		{
			j=-1;
		}
		else if(s[i]==']')//End
		{
			j=n2-1;
		}
		else if(s[i]=='{')//左
		{
			if(j>=0) j--;
		}
		else if(s[i]=='}')//右
		{
			if(j<n2-1) j++;
		}
		else if(s[i]=='-')//Insert
		{
			flag*=-1;//切换Insert状态
		}
		else if(s[i]=='=')//删除
		{
			if(n2==0) continue;
			s2.erase(j,1);
			n2--;
			j--;
		}
		else//
		{
			if(flag==1) 
			{
				s2.insert(j+1,1,s[i]);//插入
				j++;
				n2++;
			}
			else if(flag==-1)//覆盖输入下一位
			{
				if(j<n2-1)s2.erase(j+1,1);
				s2.insert(j+1,1,s[i]);//插入
				j++;
			}
		}
	}
	cout<<s2<<endl;
	return 0;
}