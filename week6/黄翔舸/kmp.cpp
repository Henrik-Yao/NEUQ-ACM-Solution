#include<iostream>
#include<cstring>
using namespace std;
int n;
char x;
string zh[1009];
string mm[1009];
void zhuce(string zh)
{
    int f = 0;
    for (int i = 0; i < n; i++)
    {
        if (zh == zh[i])
        {
            f = 1;
            break;
        }
    }
    if (f == 1)cout << "Repeated!" << endl;
    else if (f == 1)cout << "Signed!" << endl;
}
void bianyi(string zh, string mm)
{
    int f = 0;
    for (int i = 0; i < n; i++)
    {
        if (zh == zh[i])
        {
            f = 1;
            break;
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        x = getchar();
        string a, b;
        cin >> a;
        cin >> b;
        if (x == 'R')
        {
            zh[i] = a;
            mm[i] = b;
        }
    }
    return 0;
}