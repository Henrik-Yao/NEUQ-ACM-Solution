#include <iostream>
#include<string.h>
using namespace std;
char zc[1000001];//记录主串
char mc[1000001];//记录模式串
int nextt[1000001];
int	len[1000001];//各个小字符串的长度
int cdmc;//模式串长度
int cdzc;//主串长度
int gs = 0;//小字符串的个数
int wz = 0;//d第几个个小字符串
long long sum = 0;
int endll = 0;//最终结果
void get_next() 
{
	int r1, r2;
	r1 = -1;
	r2 = 0;
	nextt[0] = -1;
	while (r2 < cdmc) 
	{
		if (r1 == -1 || mc[r1] == mc[r2]) nextt[++r2] = ++r1;
		else r1 = nextt[r1];
	}
}
int kmp() 
{
	int rzc = 0;
	int rmc = 0;
	while (rzc < cdzc) 
	{
		if (rzc < len[wz]) 
		{
			if (rmc == -1 || zc[rzc] == mc[rmc]) 
			{
				rzc++;
				rmc++;
			}
			else rmc = nextt[rmc];
			if (cdmc == rmc) 
			{
				sum++;
				rmc = nextt[rmc];
				rzc = len[wz];
				wz++;
				endll++;
			}
		}
		else 
		{
			rzc = len[wz];
			wz++;
		}
	}
	return endll;
}
int main() 
{
	cin.getline(zc, 1000000000);
	cin.getline(mc, 10000);
	cdzc = strlen(zc);
	cdmc = strlen(mc);
	for (int i = 0; i < cdmc; i++) 
		if (mc[i] >= 'A' && mc[i] <= 'Z')
			mc[i] = mc[i] - 'A' + 'a';
	for (int i = 0; i < cdzc; i++) 
	{
		if (zc[i] >= 'A'&& zc[i] <= 'Z' )
			zc[i] = zc[i] - 'A' + 'a';
		
	}
    for (int i = 0; i < cdzc; i++) 
		if ((zc[i] >= 'a' && zc[i] <= 'z') &&  (zc[i + 1] < 'a' || zc[i + 1] > 'z'))
			len[gs++] = i + 1;
	get_next();
	cout << kmp();
}