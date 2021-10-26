#include <iostream>
using namespace std;
void bgpx(int*a, int q1, int q2,int*c)//[q1,q2]
{
	if (q2 - q1 == 1)//两元素
	{
		if (a[q1] > a[q2])
		{
			int zj = a[q1];
			a[q1] = a[q2];
			a[q2] = zj;
		}
		return;
	}
	else if (q2 - q1 > 1)
	{
		bgpx(a, q1, (q1 + q2) / 2, c);//左
		bgpx(a, (q1 + q2) / 2 + 1, q2, c);//右
		int fgx = (q2 + q1) / 2+1;//分割线,[q1,fgx)[fgx,q2]
		int qw = q1, qw1 = q1;
		while (qw1 < (q2 + q1) / 2+1 && fgx < q2 + 1)
		{
			//对分别已经排好序的左区间和右区间进行合并
			if (a[qw1] <= a[fgx])
			{
				c[qw] = a[qw1];
				qw++;
				qw1++;
			}
			else
			{
				c[qw] = a[fgx];
				qw++;
				fgx++;
			}
		}
		
		while (qw1 < (q2 + q1) / 2+1)//此时fgx已经等于q2+1
		{
			c[qw] = a[qw1];
			qw++;
			qw1++;
		}
		while (fgx < q2 + 1)//此时q1已经等于(q2 + q1) / 2+1
		{
			c[qw] = a[fgx];
			qw++;
			fgx++;
		}
		for (int i = q1;i < q2 + 1;i++)
			a[i] = c[i];
	}
	else
		return;
}
int c[100000];
int a[100000];
int main()
{
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> a[i];
	int q1 = 0, q2 = n-1;
	bgpx(a, q1, q2, c);
	for (int i = 0;i < n;i++)
		cout << c[i] << " ";
}