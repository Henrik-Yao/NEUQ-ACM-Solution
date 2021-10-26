#include<bits/stdc++.h>

using namespace std;

void Merge(int a[],int q,int z,int h)//进行前后半比较,排序
{
    int t[h-q+1];//q（前）到h（后）共h-q+1个数
    for(int i=q;i<=h;i++)
    {
        t[i-q]=a[i];//从0开始逐个赋值
    }
    int m,n,r;
    m=q;//带指前
    n=z+1;//带指中
    for(r=q;r<=h;r++)
    {
        if(m>z)//证明前半的数已经用完，只需把后半的数依次放入
        {
            a[r]=t[n-q];
            n++;//放入后指向下一位
        }
        else if(n>h)//后半的已排好，直接放前面的
        {
            a[r]=t[m-q];
            m++;
        }
        //还未排好,则比较前首和后首大小
        else if(t[m-q]>t[n-q])
        {
            a[r]=t[n-q];//后首小，把后首赋给a
            n++;//往后移
        }
        else if(t[m-q]<=t[n-q])
        {
            a[r]=t[m-q];//前首小
            m++;
        }
    }


}

void merge_sort(int a[],int q,int h)//划分并排序
{
    if(q<h)
    {
      int z=(q+h)/2;
      merge_sort(a,q,z);//前半
      merge_sort(a,z+1,h);//后半
      Merge(a,q,z,h);//合并
    }
}


int main()
{
    int n;
    cin>>n;
    int c[n];
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    merge_sort(c,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<c[i]<<" ";
    }
    return 0;
}
