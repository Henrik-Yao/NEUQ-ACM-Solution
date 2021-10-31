#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000];
void hnt()
{
    for(int i=3;i<64;i++)
    {
        int min1=999999;
        int temp;
        for(int j=1;j<i;j++)
        {
            temp=2*a[j]+pow(2,i-j)-1;
            if(temp<min1)
                min1=temp;
        }
        a[i]=min1;
    }
}

signed main()
{
	a[0]=0;
    a[1]=1;
    a[2]=3;
    a[64]=18433;
    hnt();
    while(cin>>n)
    {
        cout<<a[n]<<endl;
    }
    return 0;
}
