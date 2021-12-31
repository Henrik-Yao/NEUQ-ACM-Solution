#include <bits/stdc++.h>
using namespace std;
void hanoi(string now, string target, string temp, int time)
{
    if (time == 2)
    {
        cout << now << "->" << temp << endl;
        cout << now << "->" << target << endl;
        cout << temp << "->" << target << endl;
    }
    else if (time == 1)
    {
        cout << now << "->" << target << endl;
    }
    else
    {
        time--;
        hanoi(now, temp, target, time);
        cout << now << "->" << target << endl;
        hanoi(temp, target, now, time);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    string a, b, c;
    getline(cin, a);
    getline(cin, b);
    getline(cin, c);
    hanoi(a, c, b, n);
    return 0;
}
