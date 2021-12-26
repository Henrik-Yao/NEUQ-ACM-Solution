#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
string a;
int main()
{
	//			  01234
    cin>>a;
	// int i = strlen(a);
	int i = a.length();
	for (int j = 0, k = i - 1; j <= k && k >= 0; j++, k--)
	{
		if (a[j] != a[k])
		{
			cout << "no";
			return 0;
		}
	}
	cout << "yes";
	return 0;


}
