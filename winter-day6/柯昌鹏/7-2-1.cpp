#include <bits/stdc++.h>
using namespace std;

struct stu 
{
    string name;
    int sore;
}stud[20];

int main ()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>stud[i].name;
        cin>>stud[i].sore;
    }
    for(int i=0;i<n-1;i++)//冒泡排序
    {
        for(int j=i+1;j<n;j++)
        {
            if(stud[i].sore<stud[j].sore)
            {
                swap(stud[i],stud[j]);
            }
            else if(stud[i].sore==stud[j].sore)
            {
                if(stud[i].name>stud[j].name)//注意排序条件的实现情况
                {
                    swap(stud[i],stud[j]);
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<stud[i].name<<" ";
        cout<<stud[i].sore;
        if(i!=n-1) cout<<endl;
    }
    
    return 0;
}