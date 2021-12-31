#include<iostream>
using namespace std;
void aa(){

int i = 0, j = 0;
    const int len = 10;
    int p[len] = { 0, 7, 7, 6, 1, 1, 5, 5, 8, 9 };

    sort(p, p + len);   

    while (i < len) {
        if (p[i] == p[++j]) { 
            p[j] = -1;        
        } else {
            i = j;
        }
    }

    for (i = 0; i < len; i++)
        if (p[i] != -1) 
            cout << p[i] << " ";  
}
int main()
{
    int n,a[101],temp;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=2;i<=n;i++)
        {
            temp=a[i];
            int j=i-1;
            while(j>=1 && temp<a[j])
            {
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=temp;

            for(int j=1;j<=n-1;j++)
                cout<<a[j]<<" ";
            cout<<a[n]<<"\n";
        }
    }
}
