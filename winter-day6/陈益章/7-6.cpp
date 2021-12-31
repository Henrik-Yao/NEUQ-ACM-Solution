#include<bits/stdc++.h>
using namespace std;
int n;
void print(int a[],int n)
{
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
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
void quick_sort(int a[],int begin,int end)
{
    if(begin>=end) return;
    int i=begin,j=end;
    while(i!=j)
    {
        while(a[j]>a[begin] && j>i) j--;   
        while(a[i]<=a[begin] && j>i) i++;     
        swap(a[i],a[j]);
    }
    swap(a[begin],a[i]);
    print(a,n);
    quick_sort(a,begin,i-1);
    quick_sort(a,i+1,end);
}

int main()
{
    int a[1001];
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    quick_sort(a,1,n);
    print(a,n);
    return 0;
}
