#include<bits/stdc++.h> 
using namespace std;
int main()
{
	int n;
	string a;
	cin>>n;
	cin>>a;//定义母串 
	while(n--)
	{
		string b;
		int t,sum=0;
		cin>>b;
		for(int i=0;i<=a.length()-1;i++)//重复整个母串 
		{
			t=i;//标记初始位置，防止后续不同跳过子串 
			for(int j=0;;) 
			{
				if(j==b.length())//判断为子串后跳出 
				{
					sum++;
					break;
				}
				if(a[i]==b[j])//判断每一项是否相同，相同则开始判断下一项 
				{
					i++;j++;
				}
				else
				{
					break;//如有不同则终止 
				}
			}
			i=t;//回归初始位置，进行下一次循环 
		}
		printf("%d",sum);
		if(n)
		{
			printf("\n");
		}
	}
}
