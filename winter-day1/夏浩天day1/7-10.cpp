#include<iostream>
#include<stack>
#include<string.h>
#include<fstream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<list>
#include<queue>
using namespace std;
queue<int> car[100];
int cg = 1;//car启用数量
int main()
{
	int n; cin >> n;
	n--; int lsz; cin >> lsz;
	car[1].push(lsz);
	while (n--)
	{
		int lsz; cin >> lsz;
		int xb = cg+1, mi = 99999;
		for (int i = 1; i < cg + 1; i++)
		{
			int ca = car[i].back();//ca为队尾值
			if (ca - lsz < mi && ca-lsz>0)
			{
				mi = ca - lsz; xb = i;
			}
		}
		car[xb].push(lsz);//lsz进最接近的点或cg+1
		if (xb == cg + 1)cg++;
	}
	while (!car[1].empty())
	{
        if(car[1].size()>1)
        {
            cout << car[1].front()<<" ";
		    car[1].pop();
        }
        else 
        {
            cout << car[1].front();
		    car[1].pop();
        }
	}
	cout << endl;
	cout << cg;
    cout<<endl;
}