#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int re=1,temp=2,k=2,num=0;
		for(int j=1;j<n;j++)
		{
			re+=temp;
			num++;
			if(num==k)
			{
				temp*=2;
				num=0;
				k++;
			}
		}
		cout<<re<<endl;
	}
	return 0;
}
