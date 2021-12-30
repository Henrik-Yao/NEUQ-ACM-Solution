#include<bits/stdc++.h>
using namespace std;

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