#include <deque>
#include <iostream>
using namespace std;
main()
{
    int N, M, K;
    deque<int> list;
    int point1 = 0;
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        list.push_back(i);
    }
    deque<int>::iterator point = list.begin();
    for (int i = N; i > 0; i--)
    {
        point = list.begin();
        if ((N - i) % 2) //顺时针
        {
            point1 = (K + point1) % i - 1;
            if (point1 < 0)
            {
                point1 = list.size() - 1;
            }
            point += point1;
            if (point1 >= i)
            {
                point1 -= i;
            }
        }
        else //逆时针
        {
            point1 = point1 - (M % i - 1);
            if (point1 < 0)
            {
                point1 += i;
            }
            point += point1;
            point1--;
            if(point1<0)
            {
                point1 += i-1;
            }
            if(point1>=i)
            {
                point -= i;
            }
        }
        cout << *point << ' ';
        list.erase(point);
    }
}
