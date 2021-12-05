#include<iostream>
using namespace std;

int main()
{
    int M,N;
    cin>>N>>M;
    string fx[N];
    string data[N];
    for(int i=0;i<N;i++)
    {
        cin>>fx[i];
        cin>>data[i];
    }
    for(int i=0;i<M;i++)
    {
        string s;
        cin>>s;
        bool flag = false;
        for(int j=0;j<N;j++)
        {
            if(s == data[j])
            {
                cout<<fx[j]<<endl;
                flag = true;
                break;
            }
        }
        if(flag == false)
        {
            cout<<"eh"<<endl;
        }
    }
    return 0;
}