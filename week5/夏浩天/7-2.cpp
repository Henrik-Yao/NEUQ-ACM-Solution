//ŷʽɸ
#include<iostream>
#include<cmath>
using namespace std;

int qw = 1;
int ss[10000001];
bool visited[10000001];//��10000001��Χ������Ԥ�����������ݴ�����������
int main()
{
	visited[0] = visited[1] = 1;//0��1��������
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
		else if (a < 10000001) //��Ԥ�����
		{
			if (!visited[a])//������
				cout << "1" << endl;
			else if (!visited[a - 2])cout << "2" << endl;
			else cout << "3" << endl;
		}
		else //����Ԥ����Σ���Ҫ�ֶ��ж�
		{
			int pd = 0;//0Ϊ����1Ϊ������
			for (int i = 2; i <= sqrt(a); i++)
			{
				if (visited[i])continue;
				if (a % i == 0) { pd = 1; break; }//��������
			}
			if (!pd) { cout << "1" << endl; }//Ϊ����
			else
				for (int i = 2; i <= sqrt(a); i++)
				{
					if (visited[i])continue;
					if ((a - 2) % i == 0) { pd = 2; break; }//a-2��������
				}
			if (pd == 1)cout << "2" << endl;
			else if (pd == 2)cout << "3" << endl;
		}
	}
}