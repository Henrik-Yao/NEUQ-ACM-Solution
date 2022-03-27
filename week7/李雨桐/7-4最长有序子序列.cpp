#include<iostream>
using namespace std;
int a[10005], lst[1005];
int t,n,maxi=1;
int main()
{
	cin>>t;
	while (t--)
	{
		cin>>n;
		for (int i=0; i<n;i++)
		{
			cin >> a[i];
			lst[i]=1;
		}
		for (int i=1;i<n;i++)
		{
			for (int j=0;j<i;j++)
			{
				if (a[i]>a[j] && lst[j]+1 > lst[i])
					lst[i]=lst[j] + 1;
			}

			if (lst[i] > maxi)
                maxi = lst[i];
		}
		cout << maxi <<endl;
        if(t>0)
            cout<<endl;
	}
	return 0;
}
