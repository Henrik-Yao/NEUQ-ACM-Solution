#include<iostream>
#include<string.h>
using namespace std;
bool sz[10001];//记录素数
int szx[10001];//
int main()
{
	int a, b;
	szx[0] = 2;
	int cnt = 1;
	for (int i = 2; i < 10001; i++)
	{
		int pd = 1;
		for (int j = 0;; j++)
		{
			if (!szx[j])
				break;
			if (i % szx[j] == 0)
			{
				pd = 0;
				break;
			}
		}
		if (pd)
		{
			sz[i] = 1;
			szx[cnt++] = i;
		}
	}
	while(cin >> a >> b)
    {
        int pd=1;
        for (int i = a; i <= b; i++)
		    if (sz[i])
            {if(pd)
            {cout << i;
             pd=0;
            }
             else
                 cout<<" "<<i;
            }
        cout<<endl;
    }
}