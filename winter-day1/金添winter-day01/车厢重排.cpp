#include <bits/stdc++.h>
using namespace std;
queue<int> railway[1000]; //装火车的轨道
int train[1000];          //所有火车编号
int main()
{
    int num;
    cin >> num; //火车数
    for (int i = 0; i < num; i++)
        cin >> train[i];

    int len = 1;
    railway[1].push(train[0]); //第一辆车先进队
    for (int i = 1; i < num; i++)
    {
        int contain = 0;

        for (int j = 1; j <= len; j++)
        {
            if (train[i] < railway[j].back()) //优先把车插到尾数大的队列后面
            {
                if (contain != 0 && railway[contain].back() < railway[j].back())
                    continue; //若多组符合，如果找到的轨道后面编号更大的，再换
                contain = j;
            }
        }
        if (contain) //若现有队列存在符合
        {
            railway[contain].push(train[i]);
        }
        else
        {
            railway[++len].push(train[i]);  //新建并入队
        }
  	}
            while(!railway[1].empty())
            {
            	int temp=railway[1].front();
                railway[1].pop();
                if (!railway[1].empty())
                cout<<temp<<" ";
                else cout<<temp;
            }
            cout<<endl;
     cout<<len<<endl;   
    return 0;
}