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
			jie=jiemi();//�ݹ���'����'�����һ�� 
			for(int i=0;i<n;i++) mingwen+=jie;
		}
		else if(mm==']') return mingwen;//��ѹ����ַ���
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
//dev�Ῠ����ԭ��֪ 
