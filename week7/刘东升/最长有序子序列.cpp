#include <bits/stdc++.h>
using namespace std;
int T,n;
const int M=1001; 
int a[M],judge[M];
int main()
{
	cin>>T;
	while(T--)
	{
		int answer=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",a+i);
			judge[i]=1;//�����Ĵ��� 
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				if (a[i]>a[j])
				{
					judge[i]=max(judge[i],judge[j] + 1);//�ȽϽ��������Ĵ�С 
				}
			}
			answer=max(answer,judge[i]);//ѡ�����Ľ������� 
		}
        if (T>0)  printf("%d\n\n",answer);
        else printf("%d\n",answer);
	}
	return 0;
} 
