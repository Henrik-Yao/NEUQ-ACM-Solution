#include<iostream>
using namespace std;

int a[100000];
int main()
{
	int n,m,t,flag=0;
	int i;
	cin >> n >> m;
	for(i=0; i<n; i++)
	{
		cin >> a[i];
		if(flag == 0)
			if(m <= a[i])
			{
				cout << i+1;
				flag = 1;
       	     break;
			}
	}
	if(flag == 0)
	{
		cout << n+1;
	}
    
	return 0;
}

