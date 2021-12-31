#include<bits/stdc++.h>
using namespace std;
void aa(){

int i = 0, j = 0;
    const int len = 10;
    int p[len] = { 0, 7, 7, 6, 1, 1, 5, 5, 8, 9 };

    sort(p, p + len);   

    while (i < len) {
        if (p[i] == p[++j]) { 
            p[j] = -1;        
        } else {
            i = j;
        }
    }

    for (i = 0; i < len; i++)
        if (p[i] != -1) 
            cout << p[i] << " ";  
}
struct score
{
    string name;
    int grade;
}stu[21];

bool cmp(score stu1,score stu2)
{
    if(stu1.grade!=stu2.grade)
        return stu1.grade>stu2.grade;
    else
        return stu1.name<stu2.name;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>stu[i].name>>stu[i].grade;
    sort(stu+1,stu+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        cout<<stu[i].name<<" "<<stu[i].grade;
        if(i!=n) cout<<"\n";
    }
    return 0;
}
