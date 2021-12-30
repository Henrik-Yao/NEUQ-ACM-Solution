#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, key;
	cin >> N;
	map<int, int> M;
	int i;
	for(i = 0; i < N; i++)
    {
		cin >> key;//工龄
		M[key]++;//对应工龄的人数加一
	}

	map<int, int>::iterator it;//迭代器
	for(it = M.begin(); it != M.end(); it++)//it->为键值,it->second为数值
    {
		cout << it->first << ":" << it->second << endl;
	}
	return 0;

}
