#include<bits/stdc++.h> 
using namespace std;
const int M=65;
int a[M]={0,1,3,5};
int main()
{
	int b;
	int m;
	for(int i=3;i<=64;i++)//�ҹ��ɲ���¼ 
	{
		m=999999;
		for(int r=1;r<i;r++)
		{
			if(2*a[r]+pow(2,i-r)-1<m)
				{
				m=2*a[r]+pow(2,i-r)-1;
				}
		a[i]=m;
		}
	}
	while(cin>>b)
	{
	cout<<a[b]<<endl;
	}	
	return 0;
}
