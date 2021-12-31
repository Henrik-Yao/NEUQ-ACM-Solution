#include<iostream>
using  namespace std;

int times = 0;

int findx(int a[], int x, int n)
{
    int front = 0;
    int rear = n - 1;
    while (front <= rear) 
    {
        int mid = (front + rear)/2;
        times++;
        if (x == a[mid])
        {
            cout<<mid<<endl;
            cout<<times; 
            return mid;
        }
        if(x > a[mid])
        {
            front = mid + 1;
        }
        else
        {
            rear = mid - 1;
        }

    }
    cout<<"-1"<<endl;
    cout<<times ;
    return -1;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x;
    cin >> x;
    findx(a, x, n);


}