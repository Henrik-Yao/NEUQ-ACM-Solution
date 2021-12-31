#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define Status int

Status Display(int a[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return OK;
}

Status Swap(int a[],int c,int d)
{
    int temp;
    temp = a[c];
    a[c] = a[d];
    a[d] = temp;
    return OK;
}

Status down(int a[],int x,int n)
{
    int parent = x;
    int child = 2 * x + 1;
    while(child < n)
    {
        if(child+1<n && (a[child] < a[child+1]))
        {
            child++;
        }
        if(a[parent] < a[child])
        {
            Swap(a,parent,child);
            parent = child;
        }
        child = child * 2 + 1;
    }
    return OK;
}

Status CreateHeap(int a[],int size)
{
    for(int i=size/2 -1;i>=0;i--)
    {
        down(a,i,size);
    }
    return OK;
}

Status HeapSort(int a[],int size)
{
    CreateHeap(a,size);
    Display(a,size);
    for(int i=size - 1;i>0;i--)
    {
        Swap(a,0,i);
        down(a,0,i);
        Display(a,size);
    }
    return OK;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    HeapSort(a,n);
    return 0;
}

