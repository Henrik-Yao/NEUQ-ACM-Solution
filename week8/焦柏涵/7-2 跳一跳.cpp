#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,d[1000001],site=0,sum=0;//site����ǰ����λ�ã�sum���ƶ���,���ݷ�Χ��1000000��
	cin>>n;
	for(int i=0;i<n;i++) cin>>d[i];
	n--;//�ӵ�һ��ʼ��������-1 
	while(1)
	{
		if(d[site]>=n)
		{
			sum++;break;
		}
		else
		{
			int max1=site;
			for(int i=site+1;i<=site+d[site];i++)
				if((d[i]+i)>(d[max1]+max1)) max1=i;//�ڷ�Χ��Ѱ���յ���Զ�ĵ� 
			n-=max1-site;
			site=max1;
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
