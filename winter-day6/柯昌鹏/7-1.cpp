#include <iostream>
using namespace std;

int main ()
{
    int n;
    while(cin>>n){
    int a[n],temp;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }//常规输入
    for(int i=1;i<n;i++)
    {
        temp=a[i];
        int j;
//如果在从后往前的遍历过程中遇到了比当前元素更大的元素
//就将从当前开始，到大元素之间的素组后移一位，再将当前元素放到空出来的那个位置上        
        for(j=i-1;j>=0&&temp<a[j];j--)
        {
            a[j+1]=a[j];//移动位置
        }
        a[j+1]=temp;//放置元素
        for(int k=0;k<n;k++)//输出每一步的结果
        {
            cout<<a[k];
            if(k!=n-1) cout<<" ";
        }
        cout<<endl;
    }
    }
    return 0;
}