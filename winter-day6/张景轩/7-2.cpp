#include<iostream>
using namespace std;

int main()
{
    string name[10000];
    int score[10000];

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>name[i];
        cin>>score[i];
    }

    for(int i=0;i<n;i++)
    {
        int minkey = i;
        for(int j=i+1;j<n;j++)
        {
            if(score[minkey] > score[j])
            {
                minkey = j;
            }
            if(score[minkey] == score[j])
            {
                if(name[minkey] < name[j])
                {
                    minkey = j;
                }
            }
        }
        int tempnum;
        string tempstr;
        tempnum = score[i];
        tempstr = name[i];
        score[i] = score[minkey];
        name[i] = name[minkey];
        score[minkey] = tempnum;
        name[minkey] = tempstr;
    }

    for(int i=n-1;i>=0;i--)
    {
        cout<<name[i]<<" "<<score[i]<<endl;
    }
    return 0;


}



