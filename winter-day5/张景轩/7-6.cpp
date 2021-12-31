#include<iostream>
using namespace std;

int n;

int find(int x,int a[])
{
    int head;
    int tail;
    head = 0;
    tail = n-1;
    int pos;
    while(1)
    {
        pos = (head + tail)/2;
        if(a[pos] == x)
        {
            return pos+1;
        }
        else if(a[pos] < x)
        {
            head = pos;
        }
        else if(a[pos] > x)
        {
            tail = pos;
        }
        if((head == tail-1) || (head == tail))
        {
            if(a[head] == x)
            {
                return head+1;
            }
            else if(a[tail] == x)
            {
                return tail+1;
            }
            break;
        }
    }
    return 0;
}

int main()
{
    int total=1;
    while(scanf("%d",&n)!=EOF)
    {
        if(total!=1)
        {
            cout<<endl;
        }
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(a[i]>a[j])
                {
                    int temp;
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<a[i];
            if(i<n-1)
            {
                cout<<" ";
            }
        }
        cout<<endl;
        int findTimes,findx;
        cin>>findTimes;
        for(int i=0;i<findTimes;i++)
        {
            cin>>findx;
            cout<<find(findx,a);
            if(i<findTimes-1)
            {
                cout<<" ";
            }
        }
        total++;
    }
    return 0;
}