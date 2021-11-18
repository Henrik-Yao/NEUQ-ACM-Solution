//欧式筛
#include<iostream>
#include<cmath>
using namespace std;

int qw = 1;
int ss[10000001];
bool visited[10000001];//对10000001范围的素数预处理（输入数据大俩数量级）
int main()
{
	visited[0] = visited[1] = 1;//0和1不是素数
	for (int i = 2; i <= 10000001; i++)
	{
		if (!visited[i])	ss[qw++] = i;
		for (int j = 1; j <= qw && i * ss[j] <= 10000001; j++)
		{
			visited[i * ss[j]] = 1;
			if (i % ss[j] == 0) break;
		}
	}
	long long n; cin >> n;
	for (long long i = 0; i < n; i++)
	{
		long long a; cin >> a;
		if (a % 2 == 0)cout << "2" << endl;
		else if (a < 10000001) //在预处理段
		{
			if (!visited[a])//是素数
				cout << "1" << endl;
			else if (!visited[a - 2])cout << "2" << endl;
			else cout << "3" << endl;
		}
		else //不在预处理段，需要手动判断
		{
			int pd = 0;//0为素数1为非素数
			for (int i = 2; i <= sqrt(a); i++)
			{
				if (visited[i])continue;
				if (a % i == 0) { pd = 1; break; }//不是素数
			}
			if (!pd) { cout << "1" << endl; }//为素数
			else
				for (int i = 2; i <= sqrt(a); i++)
				{
					if (visited[i])continue;
					if ((a - 2) % i == 0) { pd = 2; break; }//a-2不是素数
				}
			if (pd == 1)cout << "2" << endl;
			else if (pd == 2)cout << "3" << endl;
		}
	}
}