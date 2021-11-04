#include <iostream>
using namespace std;

int ans[41];

int main()
{
    ans[1]=0,ans[2]=1,ans[3]=2;
    for(int i=4;i<=41;i++)
    {
        ans[i]=ans[i-1]+ans[i-2];
    }
    int n;
    cin>>n;
    int m[n];
    for(int i=0;i<n;i++)
    {
    	cin>>m[i];
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[m[i]]<<endl;
	}
    return 0;
}
