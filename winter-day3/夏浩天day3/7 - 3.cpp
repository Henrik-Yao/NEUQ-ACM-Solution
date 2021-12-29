#include<iostream>
#include <string.h>
#include<vector>
#include<stdlib.h>
#include<map>
#include<string>//to_string
using namespace std;

int gs, n, f; 
map<string, bool> ma;//string为已经出现的增序列（如 4,6,13 ）
int num[21];//一刀99999（划掉）

string str(int a)
{
	return to_string(a);
}

void bl(string o,int i)//o为上一次输出的,i为上一次加入的下标
{
	if (ma[o])return;
	ma[o] = true; gs++;
	for (int j = i + 1; j < n; j++)
	{
		if (num[i] <= num[j])
			bl(o + ',' + str(num[j]), j);
	}

}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < n; i++)
	{
		if (ma[str(num[i])])f++;
		bl(str(num[i]), i);
	}
	cout << gs + f - n;
}