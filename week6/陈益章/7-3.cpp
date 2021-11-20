#include<iostream>
#include<vector>
using namespace std;

int sum=0;
vector<char>text;
vector<char>pattern;
vector<int>Next;
void getnext()
{
    int j=0,k=-1;
    Next.push_back(-1);
    while(j<pattern.size())
    {
        if(k==-1 || pattern[j]==pattern[k])
        {
            j++;
            k++;
            Next.push_back(k);
        }
        else
        {
            k=Next[k];
        }
    }
}

void getresult()
{
    int i=0,flag=0,j=0;
    while(i<text.size())
    {
        if(flag==1 && text[i]!=' ')
        {
            i++;
            continue;
        }
        if(text[i]==' ')
        {
            i++;
            j=0;
            flag=0;
            continue;
        }
        if(text[i]==pattern[j] || j==-1)
        {
            i++;
            j++;
        }
        else
        {
            j=Next[j];
        }
        if(j==pattern.size())
        {
            flag=1;
            sum++;
        }
    }
}

int main()
{
   char x;
    while(x=getchar())
    {
        if(x=='\n') break;
        else if(x>='a' && x<='z') text.push_back(x);
        else if(x>='A' && x<='Z') text.push_back(x-'A'+'a');
        else text.push_back(' ');
    }
   char pt;
    while(cin>>pt)
    {
        if(pt>='a' && pt<='z') pattern.push_back(pt);
        else if(pt>='A' && pt<='Z') pattern.push_back(pt-'A'+'a');
    }
    getnext();
    getresult();
    cout<<sum;
} 
