#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;
int n;
int a[105];
int main()
{
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<n;i++)
		{
			int end=i;//1->endΪ��ǰ���������� 
			int tem=a[end+1];//ѡ�����򲿷��е�һ���������������е�ĩβ��ǰѰ������λ�� 
			while(end>=0)
			{
				if(tem<a[end])
				{
					a[end+1]=a[end];
					end--;
				}
				else break;
			}
			a[end+1]=tem;
			for(int j=1;j<n;j++)cout<<a[j]<<" ";cout<<a[n]<<endl;
		}
	}
	return 0;
}

