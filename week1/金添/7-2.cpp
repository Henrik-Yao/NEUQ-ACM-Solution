#include <bits/stdc++.h>
using namespace std;
char a[100000];
int main()
{
    int num,n,flag;
    cin>>n;
    cin>>a;
    for(int i=0;i<n;i++)
    {
    	char ch[100];
    	cin>>ch;
    	num=0;
    	for(int j=0;j<strlen(a);j++)
    	{
    		flag=0;
    		int x=j;
    		for(int k=0;k<strlen(ch);k++)
    		{
    			if(ch[k]==a[x])
    			{ 
    			flag++;
    			x++;
    			}
				else 
				break; 
			}
			if(flag==strlen(ch))
			num++;
		}
    	cout<<num<<endl;
	}

	return 0;
}
