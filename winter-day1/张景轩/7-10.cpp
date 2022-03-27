#include<iostream>
#include<queue>
using namespace std;

queue<int> q[100];

int main() 
{
    int ways = 0;
    int total;
    cin>>total;
    for(int i=0;i<total;i++)
    {
        int x;
        cin>>x;
        bool flag = false;
        for(int j=0;j<ways;j++) 
        {
            if(q[j].back() > x) 
            {
                q[j].push(x);
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            q[ways].push(x);
            ways++;
        }
    }

    for(int i=0;i<ways;i++) 
    {
        if(q[i].back() == 1)
        {
            while(!q[i].empty())
            {
                cout << q[i].front();
                q[i].pop();
                if(!q[i].empty())
                {
                    cout << ' ';
                }
                else
                {
                    cout << endl;
                }
            }
            break;
        }
    }
    cout<<ways<<endl;

    return 0;
}