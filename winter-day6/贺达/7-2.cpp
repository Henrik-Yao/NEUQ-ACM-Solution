#include<bits/stdc++.h>
using namespace std;
int n;
struct student
{
    string name;
    int score;
};

student s[25];

void bubblesort()
{
    int i,j;
    int ts;
    string tn;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(s[j].score>s[j+1].score)//前比后大就交换
            {
                tn=s[j].name;
                s[j].name=s[j+1].name;
                s[j+1].name=tn;

                ts=s[j].score;
                s[j].score=s[j+1].score;
                s[j+1].score=ts;
            }
            else if(s[j].score==s[j+1].score)//分数相同则看名字
            {
                if(s[j].name<s[j+1].name)
                {
                    tn=s[j].name;
                    s[j].name=s[j+1].name;
                    s[j+1].name=tn;

                    ts=s[j].score;
                    s[j].score=s[j+1].score;
                    s[j+1].score=ts;
                }
            }
        }
    }
}

int main()
{

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i].name>>s[i].score;
    }
    bubblesort();
    for(int i=n-1;i>=0;i--)
    {
        cout<<s[i].name<<" "<<s[i].score<<endl;
    }
    return 0;
}
