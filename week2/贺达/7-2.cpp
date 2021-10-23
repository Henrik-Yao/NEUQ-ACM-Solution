#include<bits/stdc++.h>
using namespace std;

int b[10001];

int main()
{
	int n,m;
	cin>>n>>m;
	int a[m][2];
	for(int i=0;i<m;i++)
    {
        cin>>a[i][0];
        cin>>a[i][1];
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        memset(b,0,sizeof(b));
        int p;
        cin>>p;

        for(int j=0;j<p;j++)
        {
           int x;
           cin>>x;
           b[x]=1;
        }
        int count=0;
        for(int k=0;k<m;k++)
        {
            if(b[a[k][0]]==1||b[a[k][1]]==1)
            {
                count++;
            }
        }

        if(m==count)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }

	return 0 ;
}

