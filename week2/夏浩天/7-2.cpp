
#include<iostream>
using namespace std;
int cs1[10000], cs2[10000];//道路旁城市编号
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0;i < m;i++)//写入cs12（城市编号)
	{
		cin >> cs1[i] >> cs2[i];
	}
	int k;
	cin >> k;//k组数据
	for (int i = 0;i < k;i++)
	{
		int cszt[10001] = { 0 };//城市状态，0正常1被炸
		int n1;
		cin >> n1;//n1个城市编号
		int bh;//城市编号
		for (int j = 0; j < n1; j++)
		{
			cin >> bh;
			cszt[bh] = 1;
		}
		int pdqz = 0;//判断是否全部断掉,0全断
		for (int i = 0; i < m; i++)
		{
			if (cszt[cs1[i]] == 0 && cszt[cs2[i]] == 0)
			{
				pdqz = 1;
				cout << "NO" << endl;
				break;
			}
		}
		if (pdqz == 0)
			cout << "YES" << endl;
	}
}