#include <bits/stdc++.h>
using namespace std;
int len1,len2,ans,l,r;
char s1[1000005],s2[1000005];
int nex[1000005];
bool check(int l,int r)
{
	for (int i = l,j = 0;i <= r; i++)
	{
		while (j > 0 && (j == len2 || s1[i] != s2[j + 1])) j = nex[j];
		if (s1[i] == s2[j + 1]) j++;
//		cout << j << endl;
		if (j == len2) return 1;
	}
	return 0;
}
void init()
{
	for (int i = 1;i <= len1; i++)
	{
		if (s1[i] >= 'A' && s1[i] <= 'Z') s1[i] = s1[i] - 'A' + 'a';
	}
	for (int i = 1;i <= len2; i++)
	{
		if (s2[i] >= 'A' && s2[i] <= 'Z') s2[i] = s2[i] - 'A' + 'a';
	}
	nex[1] = 0;
	for (int i = 2,j = 0;i <= len2; i++)
	{
		while (j > 0 && s2[i] != s2[j + 1]) j = nex[j];
		if (s2[i] == s2[j + 1]) j++;
		nex[i] = j;
	//	cout << j << endl;
	}
}
int main()
{
	scanf("%[^\n]",s1 + 1);
	scanf("\n");
	scanf("%s",s2 + 1);
	s1[0] = 'a';
	s2[0] = 'a';
	len1 = strlen(s1);
	len2 = strlen(s2);
	len1--;
	len2--;
	
	
	init();
	for (int i = 1;i <= len1; i++)
	{
		if (s1[i] >= 'a' && s2[i] <= 'z')
		{
			if ((!l) && (!r))
			{
				l = i;
			}
		} else {
			if (l && (!r))
			{
				r = i - 1;
			//	cout << l << " " << r << endl;
				if (check(l,r)) ans++;
				l = r = 0;
			}
		}
	}
	if (s1[len1] >= 'a' && s1[len1] <= 'z') 
	{
		r = len1;
		if (check(l,r)) ans++;
	}
	printf("%d\n",ans);
	return 0;
} 
