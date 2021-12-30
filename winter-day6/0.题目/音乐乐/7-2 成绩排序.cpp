#include<bits/stdc++.h>
using namespace std;
struct student
{
    string name;
    int score;
}stu[101];
bool cmp(student x,student y)
{
    if(x.score!=y.score)
        return x.score>y.score;
    else return x.name<y.name;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>stu[i].name>>stu[i].score;
    }
    sort(stu,stu+n,cmp);
    for(int i=0;i<n;i++)
    {
        cout<<stu[i].name<<' '<<stu[i].score<<endl;
    }
    return 0;
} 
