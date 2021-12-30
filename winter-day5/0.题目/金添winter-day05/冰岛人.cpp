#include <bits/stdc++.h>
using namespace std;
int flag = 0;               //判断祖上有没有相同的祖先
map<string, string> people; //该人名字为指引，指向的人的名字为结果
map<string, int> sex;       // 1为男，2为女
map<string, int> visit;     //记录向上询问时找到的祖先
void judge(string surname, string name)
{
    int len = surname.size();
    if (surname[len - 4] == 's' && surname[len - 3] == 's' && surname[len - 2] == 'o' && surname[len - 1] == 'n')
    {
        string father = surname.substr(0, len - 4);
        people[name] = father;
        sex[name] = 1;
    }
    else if (surname[len - 7] == 's' && surname[len - 6] == 'd' && surname[len - 5] == 'o' && surname[len - 4] == 't' && surname[len - 3] == 't' && surname[len - 2] == 'i' && surname[len - 1] == 'r')
    {
        string father = surname.substr(0, len - 7);
        people[name] = father;
        sex[name] = 0;
    }
    else
    {
        people[name] = name; //始祖人物
        if (surname[len-1]=='m') sex[name]=1;
        else sex[name]=0;
    }
}
void find(string name, int n) //并查集
{
    if (n == 0)
    {
        // cout<<name<<endl;
        if (visit[name])
            flag = 1;
        else
            visit[name] = 1;
        return;
    }
    else
    {
        if (visit[name])
            flag = 1;
            visit[name]=1;
        find(people[name], n - 1);
    }
}
int main()
{
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        string name;
        string surname; //名和姓
        cin >> name >> surname;
        judge(surname, name);
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        string name1, surname1, name2, surname2;
        cin >> name1 >> surname1 >> name2 >> surname2;
        if (people[name1].empty() || people[name2].empty())
        {
            cout << "NA" << endl;
            continue;
        }
        if (sex[name1] == sex[name2])
        {
            cout << "Whatever" << endl;
            continue;
        }
        else
        {
            flag = 0;
            find(name1,3);
            find(name2,3);
            if(flag)
            cout<<"No"<<endl;
            else
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}