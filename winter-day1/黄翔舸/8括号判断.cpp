/*7-8 括号配对
设表达式中允许包含3种括号：圆括号、方括号和大括号。即小括号、中括号和大括号。
编写一个算法来判断表达式中的括号是否正确配对，要求利用栈的结构实现。*/
#include<iostream>
#include<cstring>
using namespace std;
int cun[10001];
int main()
{
	string  c2;
	
	long long int uq = 0;
	cin >> c2;
	long long int cd = c2.length();
	for (int i = 0; i < cd; i++)
	{


		if (c2[i] == '(' || c2[i] == ')' )
		{
			cun[uq] = 1;
			uq++;

		}
		else if (c2[i] == '[' || c2[i] == ']')
		{
			cun[uq] = 2;
			uq++;
		}
		else if (c2[i] == '{' || c2[i] == '}')
		{
			cun[uq] = 3;
			uq++;
		}

	}
	int flag = 0;
	long long int y = 0;
	for (long long int e = uq - 1; e >= 0; e--)
	{
		if (cun[e] == cun[y])
		{

		}
		else
		{
			flag++;
			break;
		}
		y++;

	}
	if (flag)
	{
		cout << "no" << endl;
	}
	else
	{
		cout << "yes" << endl;
	}
	return 0;
}