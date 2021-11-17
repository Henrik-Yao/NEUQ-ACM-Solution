#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
int Next[maxn];
string pat;
string str[1000];
void next()
{
	int i=0,j=-1;
	Next[0]=-1;
	while(i<pat.size())
	{
		if(j==-1||pat[i]==pat[j])
		{
			i++;
			j++;
			Next[i]=j;
		}//j=-1为刚开始，且是使j自加的条件，s[i]==s[j]时是指结束的部位与前面的第几个相等
		else
		j=Next[j];  //查看已经重复的字符串里是否有可以重复的，如果有，看是否接得上
	}
}
int ads;
void  kmp(string text)
{
	int i=0,j=0;
	ads=0;
	while(i<text.size())
	{
		if(j==-1||text[i]==pat[j])
		{
			j++;
			i++;
			
		}
		else j=Next[j];
		if(j==pat.size()) ads++;
	}
}

int main()
{
	char c;
	int i=0;
	while(c=getchar())
	{
		if(c=='\n') break;
		if(c>='a'&&c<='z')
		str[i]+=c;
		else if(c>='A'&&c<='Z') str[i]+=(c-('A'-'a'));
		else if(str[i]=="\0") continue;
		else i++;	
	}
	cin>>pat;
	for(int i=0;i<pat.size();i++) if(pat[i]<'a') pat[i]-=('A'-'a');
	int ans=0;
	i++;
	next();
	while(i--)
	{
		if(str[i]=="\0") continue;
		kmp(str[i]);
		if(ads) ans++;
	}
	cout<<ans;
	return 0;
}