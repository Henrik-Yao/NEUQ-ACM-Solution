#include<bits/stdc++.h>
using namespace std;
long long int n,a[1000]={0,1,3,5};
void HN();
int main()
{  a[64]=18433;
    HN();
    while(cin>>n)
    {
        printf("%d",a[n]);
        cout<<endl;
    }
    return 0;
}

void HN()
{   
for(int i=3;i<64;i++)
    {long long int b=9999999,c;
    for(int j=1;j<i;j++)
    {c=2*a[j]+pow(2,i-j)-1;
     if(c<b)
	  {
	 
                b=c;
      }
    }
       a[i]=b; 
    }
}
