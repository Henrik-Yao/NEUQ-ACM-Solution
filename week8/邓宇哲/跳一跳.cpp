#include <iostream>
using namespace std;
main()
{
    long n, step = 0;
    long long maxt;
    cin >> n;
    long long *list = new long long[n];
    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
    }
    long point = 0;
    bool sign=0;
    while (point < n - 1)
    {
        maxt =0;
        step++;
        for (long i = point + 1; (i <= point + list[point]) && i < n; i++)
        {   
            if(list[point]+point>=n-1)
            {
                sign = 1;
                break;
            }
            if(list[i] + i>=list[maxt+point]+point+maxt)
            {
                maxt = i-point;
            }
        }
        if(sign==1)
        {
            break;
        }
        point += maxt;
        
    }
    cout << step ;
    delete[] list;
}