#include <iostream>
using namespace std;
int main ()
{
	int n;
	string a,b;
	cin>>n;
	int c[n];
	cin>>a;
	for(int i=0;i<n;i++)
	{
		cin>>b;
		int q=0;
		for (int j = 0; j < a.length(); j++) {
           int  flag=1;
            for (int k = 0; k < b.length(); k++) {
                if (a[j+k] != b[k]) {
                    flag= 0;
                }
            }
            if (flag== 1) {
                q++;
            }
		}
		c[i]=q;
	}
	for(int i=0;i<n;i++)
	{
		cout<<c[i]<<endl;
	}
	return 0;
}
