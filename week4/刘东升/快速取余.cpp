#include<bits/stdc++.h>
using namespace std;
long long int kuai(long long int a,long long int b,long long int c)
{
	long long int ans=1;
	while(b)
	{
		if(b%2==1)//���Ϊż���η� ��ת��Ϊ������ 
		{
			ans=ans*a%c; 
		}
		b=b/2;
		a=a*a%c;//������mol c����������� 
	} 
	return ans;
}
int main()
{
	long long int t,a,b,c;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c;
		cout<<kuai(a,b,c)<<endl;
	}
}
