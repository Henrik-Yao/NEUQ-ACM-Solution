#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 110;
int a[N],b[N];

int n , m;
int main()
{
  ios::sync_with_stdio(false);
  int t;
  cin >> t;

  while (t --)
  {
    vector<int> c;
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    {
      cin >> a[i];
      c.push_back(a[i]);
    }
    cin >> m;
    for (int i = 1; i <= m; ++ i)
    {
      cin >> b[i];
      c.push_back(b[i]);
    }

    sort(c.begin() , c.end());
    for (int i = 0; i < c.size(); ++ i)
    {
      cout << c[i];
      if ( i < c.size() - 1) cout << " ";
    }
    cout << endl;
  }
  return 0;
}

//设置两个数值，并对其进行归并排列