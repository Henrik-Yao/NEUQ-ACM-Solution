#include<iostream>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<n;i++)
        {
            int temp = a[i];
            int j = i - 1;
            while(j >= 0 && a[j] > temp)
            {
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = temp;
            
            for(int k=0;k<n;k++)
            {
                cout<<a[k];
                if(k<n-1)
                {
                    cout<<" ";
                }
            }
            cout<<endl;
        }
    }
    
    return 0;
}