#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
	unsigned long long a[65];
    while(cin>>n)
    {
        int i,j;		
        a[1]=1;
        for(i=2;i<=n;i++)
        {
            unsigned long long min=pow(2,i)-1;
            for(j=1;j<i;j++)
            {
                unsigned long long k=2*a[j]+pow(2,i-j)-1;
                if(k<min)
                {  
				    min=k;
				}             
            }
            a[i]=min;
        }
        cout<<a[n]<<endl;
    }
    return 0;
}
