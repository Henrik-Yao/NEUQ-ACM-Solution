#include<bits/stdc++.h>
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
void print(int a[],int n)
{
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}

void down(int a[],int i,int n)
{
    int father=i;
    int son=2*i;
    while(son<=n)
    {
        if(son+1<=n && a[son]<a[son+1]) son++;
        if(a[father]<a[son])
        {
            swap(a[son],a[father]);
            father=son;
        }
        son=son*2;
    }
}

void BuildHeap(int a[],int n)
{
    for(int i=n;i>=1;i--)
    {
        down(a,i,n);
    }
}

void HeapSort(int a[],int n)
{
    BuildHeap(a,n);
    print(a,n);
    for(int i=n;i>1;i--)
    {
        swap(a[1],a[i]);
        down(a,1,i-1);
        print(a,n);
    }
}

int main()
{
    int n,a[1001];
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    HeapSort(a,n);
    return 0;
}
