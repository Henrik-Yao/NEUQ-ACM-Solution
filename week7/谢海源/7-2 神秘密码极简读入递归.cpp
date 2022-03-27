#include<bits/stdc++.h>
using namespace std;
string read()
{
	int n;
	string s="",s1;
	char c;
	while (cin>>c)//一直读入字符，直到Ctrl+z
	{
		if (c=='[')
		{
			cin>>n;//读入D
			s1=read();//读入X
			while (n--) s+=s1;//重复D次X
            //注：上面不能写成while (n--) s+=read();
		}
		else 
		{
			if (c==']') return s;//返回X
		    else s+=c;//如果不是'['和']'，那就是X的一个字符，所以加进X
		}
	}
}
int main()//巨短主函数
{
	cout<<read(); 
	return 0;
}