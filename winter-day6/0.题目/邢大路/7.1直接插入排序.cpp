#include<iostream>
using namespace std;
int main(){
    int n;
    while(cin>>n){
    int a[n+1];
    for(int i=0;i<n;i++)cin>>a[i];
    int i,j;
    for(i=1;i<n;i++)
    {
        if(a[i]<a[i-1])
        {
            int temp=a[i];
            for(j=i-1;j>=0&&a[j]>temp;j--)
            {
                a[j+1]=a[j];
            }
            a[j+1]=temp;
        }
        for(int k=0;k<n;k++)
    {
        cout<<a[k];
        if(k!=n-1)cout<<" ";
    }
        cout<<endl;
        
    }
    }
    return 0;
}
