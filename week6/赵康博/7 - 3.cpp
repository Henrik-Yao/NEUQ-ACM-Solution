#include <bits/stdc++.h>
using namespace std;
#define N 200
int Next[N];
char Test[N];
int t1 = 0;
void Wnext(){
    int i = 0;
    int j = -1;
    Next[0] = -1;
    while (i!=t1-1)
    {
        if(j==-1 || Test[i] == Test[j])
        {
            i++;j++;
            Next[i] = j;
        }
        else j = Next[j];
    }
}
int P(string s){
    int s1 = s.size();
    int i = 0,j = 0;
    while (i!=s1)
    {
     if(s[i]==Test[j]||j == -1){
         i++;
         j++;
         if(j==t1)
         {
             return 1;
         } 
     }
     else
     {
         j = Next[j];
     }
    }
    return 0;
} 
int main(){
    string s[200];
    int i = 0;
    int sum = 0;
    char t = getchar();
    while (1)
    {
        if(t>='a'&&t<='z')s[i]+=t;
        else if(t>='A'&&t<='Z')s[i]+=t - 'A' + 'a';
        else if(t == '\n')break;
        else {
            t = getchar();
            if(t>='a'&&t<='z'||t>='A'&&t<='Z'){
                i++;
            }
            continue;
        }
        t = getchar();
    }
    cin>>Test;
    t1 = strlen(Test);
    for(int j = 0; j < t1; j++)
    {
        Test[j] = tolower(Test[j]);
    }
    Wnext();
    for(int j = 0; j <= i; j++)
    {
        if(P(s[j]))sum++;
    }
    cout<<sum;
    return 0;
}