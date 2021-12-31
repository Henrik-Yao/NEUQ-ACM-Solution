#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void paxu(int a[],int begin,int end)
{
	if(begin==end)
	{
		for(int i=1;i<=end;i++) cout<<(char)a[i]; 
		cout<<"\n";
		return ;
	}
	else
	{
        sort(a+begin,a+end+1);
		for(int i=begin;i<=end;i++)
		{
			swap(a[i],a[begin]); 
			paxu(a,begin+1,end);
			sort(a+begin,a+end+1);
	    }
    }
}

int main()
{
	int a[10],len=0;
	char x;
	while(cin>>x)
	{
		len++;
		a[len]=(int)x;
	}
	sort(a+1,a+1+len);
	paxu(a,1,len);
	return 0;
}