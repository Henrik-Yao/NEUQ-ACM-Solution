#include <bits/stdc++.h>
using namespace std;
string jiemi()
{
	int n;
	char mm;
	string jie,mingwen;
	while(cin>>mm)
	{
		if(mm=='[')
		{
			cin>>n;
			jie=jiemi();//递归至'【】'的最后一层 
			for(int i=0;i<n;i++) mingwen+=jie;
		}
		else if(mm==']') return mingwen;//解压后的字符串
		else mingwen+=mm; 
		if(mm=='\n') return mingwen;
	}
}
int main()
{
	string daan;
	daan=jiemi();
	cout<<daan;
	return 0;
}
//dev会卡死，原因不知 
