#include <iostream>
using namespace std;
int n;
int z=0;
int a[10000];
int sc[10000][10000];
int main()
{
  
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    
    for (int i=1; i<=n; i++)
    {
        if(a[i]<0) z++;
    }
    
    if(z==n) {cout<<0;return 0;} 
    else{
    
            for (int i=1; i<=n; i++) sc[i][i] = a[i];  
 
            for (int r=2; r<=n; r++)
            {
                for(int i=1 ; i<=n-r+1 ;i++)
                {
                    sc[i][i+r-1]=a[i];  
                    for(int j=i+1; j<=i+r-1 ;j++)  
                        sc[i][i+r-1]+=a[j];    
                }
            }
            
            int sum=sc[1][1];
            for (int i=1; i<=n; i++)
            {
                for (int j=i; j<=n; j++)
                {
                    if(sum<sc[i][j]) sum=sc[i][j];   
                }
            }
            cout<<sum;
        }
}
