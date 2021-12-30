#include<bits/stdc++.h>
using namespace std;
int n;
int a[1010];
void show();
void quicksort(int low,int high)
{
    if(low>=high) return;
    int i=low;
    int j=high;
    int mark = a[i];//以第一个数为基准
    while(i<j) //终止条件
    {
        while(i<j && a[j]>mark)//先移动high指针，找到比标准更小的数
        {
            j--;
        }
        while(i<j && a[i] <= mark)//再移动low指针，直到找到比基准大的位置
        {
            i++;
        }
        if(i<j) swap(a[i],a[j]);
    }
    swap(a[low],a[i]);
    int flag = 1;  //避免重复无效的排序
    for(int k=0;k<n;k++)
    {
        cout<<a[k]<<" ";
        if(k!=0&&a[k-1]>a[k])
        {
            flag = 0;
        }
    }
    cout<<endl;
    if(flag)
    {
        return;
    }
    quicksort(low,j-1);
    quicksort(i+1,high);
}



int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quicksort(0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
