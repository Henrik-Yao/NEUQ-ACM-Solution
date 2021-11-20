#include <bits/stdc++.h>
using namespace std;
#define N (int)1e6
int Next[N];
char s[N];
char t[N];
int s1 = 0,t1 = 0;
void Wnext(){
    int i = 0;
    int j = -1;
    Next[0] = -1;
    while (i!=t1-1)
    {
        if(j==-1 || t[i] == t[j])
        {
            i++;j++;
            Next[i] = j;
        }
        else j = Next[j];
    }
}
void P(){
    int sum = 0;
    int i = 0,j = 0;
    while (i!=s1)
    {
     if(s[i]==t[j]||j == -1){
         i++;
         j++;
         if(j==t1)
         {
         i--;
         sum++;
         j = Next[j-1];
         } 
     }
     else
     {
         j = Next[j];
     }
    }
    printf("%d\n",sum);
} 
int main(){
    while((s[s1]=getchar())!='\n')s1++;
    while((t[t1]=getchar())!='\n')t1++;
    Wnext();
    P();
    return 0;
}
