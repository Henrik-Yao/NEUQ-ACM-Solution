#include <iostream>
#include<algorithm>
using namespace std;
struct student
{
    string name;
    int num;
};
bool cmp(student a, student b)
{
    if (a.num != b.num)
        return a.num > b.num;
    else
        return a.name < b.name;
}
int main()
{
    int n;
    cin >> n;
    student lsz[100];
    for (int i = 0; i < n; i++)
    {
        cin >> lsz[i].name >> lsz[i].num;
    }
    sort(lsz, lsz + n, cmp);
    for (int i = 0; i < n; i++)
    {
        cout << lsz[i].name << " " << lsz[i].num << endl;
    }
    return 0;
}