#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

stack <char> s;
queue <char> q;

int main ()
{
    
    char data;
    char s1[105];

    cin>>s1;
    for (int i = 0;i < strlen(s1);i++)
    {
        q.push(s1[i]);
    }
    while (!q.empty()) 
    {
        if (q.front() == 'A')
        {
            cout<<"sae";
        }
        else if (q.front() == 'B')
        {
            cout<<"tsaedsae";
        } 
        else if (q.front() == '(')
        {
            q.pop();
            data = q.front();
            q.pop();

            while (q.front() != ')')
            {
                s.push(q.front());
                q.pop();
            }
            while (!s.empty())
            {
                if (s.top() == 'A')
                {
                    cout << data << "sae";
                }
                else if (s.top() == 'B')
                {
                    cout<<data<<"tsaedsae";
                }
                else cout<<data<<s.top();
                s.pop();
            }
            cout << data;
        }
        else if (q.front() == ')')
        {
            q.pop();
        }
        else if(q.front() == '#')
        {
            continue;
        }
        else
        {
            cout<<q.front();
        }
        q.pop();
    }
    cout << endl;
    return 0;
}
