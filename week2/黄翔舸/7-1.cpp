#include<iostream>
#include<cstring>//包含字符串的头文件

using namespace std;
int main()
{
	void han(int n, string a, string b, string c);//函数声明
	int n;
	cin >> n;
	string a, b, c;
	cin >> a >> b >> c;
	han(n, a, b, c);


	return 0;

}
void han(int n, string a, string b, string c)//定义函数
{
	if (n == 1)
	{
		cout << a << "->" << c << endl;//如果n=1根据题意直接将其移到c即可
	}
	else//对于n个盘子，首先将n-1个盘子移动到b上（注意由于n=1是的定义是a到c的移动，所以在下面书写时要想a移动到b，应当是acb的书写）

		​	       //接着执行最后一个盘子从a到c的移动

		​           //完成后再将n-1个盘子移动上去即从b到c所以为bac

	{
			han(n - 1, a, c, b);
			cout << a << "->" << c << endl;
			han(n - 1, b, a, c);
	}

}