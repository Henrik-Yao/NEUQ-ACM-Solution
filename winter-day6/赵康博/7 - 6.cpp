#include <bits/stdc++.h>
using namespace std;
#define N (int)1e5
int s[N];
  int n;
void QuickSort(int l,int r)
{
    if(l >= r)return ;
    int key = s[l];
    int first = l;
    int last = r;
    while(first<last)
    {
        while(first < last &&key < s[last])
        {
            last--;
        }
        while(first < last &&s[first] <= key)
        {
            first++;
        }
        if(last > first)
        {
            int t  = s[last];
            s[last] = s[first];
            s[first] = t;
        }
    }
    s[l] = s[first];
    s[first] = key;
    for(int i = 0 ; i < n; i++)cout<<s[i]<<" ";
    cout<<endl;
    QuickSort(l,first - 1);
    QuickSort(first + 1,r);
}

int main()
{
    cin>>n;
    for(int i = 0; i < n; i++)cin>>s[i];
    QuickSort(0,n-1);
     for(int i = 0 ; i < n; i++)cout<<s[i]<<" ";
    cout<<endl;
}