#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    char c;
    bool atate=0;
    int count=0,sum=0;
    while(1)
    {
            if((c=getchar())=='\n') break;
            else int t=1;
            if(c=='-')
            {
                if(atate) atate=0;
                else atate=1;
            }
            else if(c=='{') 
            {
                if(count>0) count--;
            }
            else if(c=='}') 
            {
                if(count<sum) count++;
            }
            else if(c=='[') count=0;
            else if(c==']') count=sum;
            else if(c=='=') 
            {
                if(count>0)  
            {
                str.erase(count-1,1);
                count--,sum--;
            }
            }
           else
           {
                if(atate&&count!=sum) 
                {
                    str.replace(count,1,1,c);
                    count++;
                }
               else
               {
                    str.insert(count,1,c);
                    count++;
                    sum++;
               }
           }
    }
    cout<<str;
    return 0;
}
