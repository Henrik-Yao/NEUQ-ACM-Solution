/*7-8 �������
����ʽ���������3�����ţ�Բ���š������źʹ����š���С���š������źʹ����š�
��дһ���㷨���жϱ��ʽ�е������Ƿ���ȷ��ԣ�Ҫ������ջ�Ľṹʵ�֡�*/
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