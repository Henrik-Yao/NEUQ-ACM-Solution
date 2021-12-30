#include <bits/stdc++.h>
using namespace std;
int search(int a[], int len, int tar)
{//左闭右开二分查找
    int left=0;
    int right=len;
    while(left<right)
    {
        int mid=(left+right)/2;
        if(a[mid]>tar)
        {
            right=mid;
        }
        else if(a[mid]<tar)
        {
            left=mid+1;
        }
        else
        return mid;
    }
    return -1;
}
int main()
{
    int len;
    while (cin >> len)
    {
        int a[100];
        for (int i = 0; i < len; i++)
        {
            cin >> a[i];
        }
        sort(a, a + len);
        queue<int> line;
        int num;
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            int tar;
            cin >> tar;
            line.push(search(a, len, tar)+1);
        }
        for (int i = 0; i < len-1; i++)
            cout << a[i] << " ";
            cout<<a[len-1]<<endl;
        while(line.size()!=1)
        {
            cout<<line.front()<<" ";
            line.pop();
        }
        cout<<line.front();
        cout<<endl;
    }

    return 0;
}