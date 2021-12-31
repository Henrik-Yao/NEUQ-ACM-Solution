#include <bits/stdc++.h>
using namespace std;
int n;
void heapadjust(vector<int>&a,int s,int m)
{
    int x = a[s];
    for(int i = s * 2;i <= m;i *= 2)
	{
        if(i < m && a[i] < a[i + 1]){i++;}
        if(x >= a[i]){break;}
        a[s] = a[i];
        s = i;
    }    
    a[s] = x;
}
void createheap(vector<int>&a)
{
    for(int i = n / 2;i > 0;i--)
	{
        heapadjust(a,i,n);
    }
}
void heapsort(vector<int>&a)
{
    createheap(a);
    for(int i = 1;i <= n;i++){printf("%d ",a[i]);}
    puts(""); //注意 
    for(int i = n;i > 1;i--)
	{
        swap(a[1],a[i]);
        heapadjust(a,1,i - 1);
        for(int i = 1;i <= n;i++)
        printf("%d ",a[i]);
        puts("");  //注意 
    }
    
}
int main()
{
    vector<int>a;
    scanf("%d",&n);
    a.resize(n + 1);
    for(int i = 1;i <= n;i++)
	{
        scanf("%d",&a[i]);
    }
    heapsort(a);
    return 0;
}
