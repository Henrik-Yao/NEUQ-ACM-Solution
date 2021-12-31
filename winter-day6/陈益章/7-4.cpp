#include<bits/stdc++.h>
using namespace std;
long a[500001],t[500001];
long long ans=0;

void merge_sort(int begin,int end)
{
    if(begin==end) return ;
    int mid=(begin+end)/2;
    merge_sort(begin,mid);
    merge_sort(mid+1,end);
    int i=begin,j=mid+1,k=0;
    while(i<=mid && j<=end)
    {
        if(a[i]<=a[j])
        {
            t[k]=a[i];
            k++;i++;
        }
        else
        {
            t[k]=a[j];
            k++;j++;
            ans=ans+mid-i+1;
        }
    }
    while(i<=mid)
    {
        t[k]=a[i];
        k++;i++;
    }
    while(j<=end)
    {
        t[k]=a[j];
        k++;j++;
    }
    for(int i=0;i<k;i++)
        a[begin+i]=t[i];
}
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
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    merge_sort(1,n);
    cout<<ans;
    return 0;
}
