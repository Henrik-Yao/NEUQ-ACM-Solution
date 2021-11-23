#include <bits/stdc++.h>
using namespace std;
char s1[1000011], s2[1000011];
int kmp[1000011], l_1, l_2, cnt, j;

int main(void)
{
    cin.getline(s1+1,1000011,'\n');
    cin.getline(s2+1,1000011,'\n');
    l_1=strlen(s1+1);
    l_2=strlen(s2+1);
    
    for(int i=1;i<=l_1; i++)
    	if(s1[i]>='A' && s1[i]<='Z')
    		s1[i]+=32;
    		
    for(int i=1; i<=l_2; i++)
    	if(s2[i]>='A' && s2[i]<='Z')
   			s2[i] += 32;
   			
    for(int i=2; i<=l_2; i++)
	{
        while(j && s2[i] != s2[j + 1])
        	    j=kmp[j];
        if(s2[j+1]==s2[i])j++;
            kmp[i]=j;
    }
    j=0;

    bool flag=true, first=true;
    for(int i=1; i<=l_1; i++)
	{
        if(s1[i]<'a'||s1[i]>'z')
        flag=false;
        while(j>0 && s2[j+1]!=s1[i])
        j = kmp[j];
        if(s2[j+1]==s1[i])
        j++;
        if(j==l_2)
		{
            if(!flag||first)
			{
            cnt++;
            flag=true;
            first=false;
            }
            j=kmp[j];
        }
    }
    cout<<cnt;
    
    return 0;
}
