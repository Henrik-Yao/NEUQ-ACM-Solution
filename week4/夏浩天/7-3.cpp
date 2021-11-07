//欧式筛
#include<iostream>
using namespace std;

int qw=1, n;
int ss[100000001];
bool visited[100000001];//默认全为素数
int main()
{
	cin >> n;
	visited[0] = visited[1] = 1;//0和1不是素数
	for (int i = 2; i <= n; ++i) 
	{
		if (!visited[i])	ss[qw++] = i;
		for (int j = 1; j <= qw && i * ss[j] <= n; j++) 
		{
			visited[i * ss[j]] = 1;
			if (i % ss[j] == 0) break;
		}
	}
	long long edd = 0;
	for (int i = 2; i <= n; ++i)
		if (!visited[i]) edd++;
	cout << edd <<endl;
}



//埃氏筛
#include<iostream>
#include<iomanip>
using namespace std;
bool is_prime[10000000];//布尔数组来标记是否为素数
int prime[10000000];    //存放素数
int q = 0;
int main() //要筛选素数的区间右端点
{
    int b;
    cin >> b;
    for (int i = 2; i <= b; i++)
    {
        if (!is_prime[i])
        {
            prime[q++] = i;
            for (int j = i * 2; j <= b; j += i)//素数的倍数一定不是素数
            {
                is_prime[j] = 1;
            }
        }
    }
    cout << q<<endl;
}