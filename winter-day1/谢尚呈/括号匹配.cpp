#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	string stri;
	while(getline(cin, stri))
	{
		int s_left=0;//��Ҫ����߼�������ŵĸ��� 
		int n_left=0;//���е�δ���������Ÿ��� 
		for(int i=0; stri[i]!='\0'; i++)
		if(stri[i]=='(')	n_left+=1;
		else if(stri[i]==')')
		{
			if(n_left)	n_left-=1;
			else
			{
				s_left+=1;
				n_right+=1;
			}
		}
		else;
		int s_right=n_left;
		if(s_left+s_right==0)	cout<<"Match"<<endl;
		else
		{
			cout<<s_left+s_right<<endl;
			for(int i=0; i<s_left; i++)	cout<<"(";
			cout<<stri;
			for(int i=0; i<s_right; i++)	cout<<")";
			cout<<endl;
		}
		stri.clear();
	}
}
