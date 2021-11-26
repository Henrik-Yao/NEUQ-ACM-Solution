#include<iostream>
#include<cstring>
using namespace std;
int nex[1000011], l_txt, l_pat, j, ans=0;
char txt[1000011], pat[1000011];
int main()
{
    cin>>txt+1>>pat+1;
    l_txt=strlen(txt+1), l_pat=strlen(pat+1);
    for(int i=2;i<=l_pat;i++)
	   {
	   while(j&&pat[i]!=pat[j+1])
        j=nex[j];
       if(pat[j+1]==pat[i])j++;    
        nex[i]=j;
       }
    j=0;
    for(int i=1; i<=l_txt; i++)
	   {
          while(j>0&&pat[j+1]!=txt[i])
           j=nex[j];
          if (pat[j+1]==txt[i]) 
           j++;
          if (j==l_pat)
		  {
		  	ans++;
			j=nex[j];
		}
       }

    cout<<ans;
    return 0;
}