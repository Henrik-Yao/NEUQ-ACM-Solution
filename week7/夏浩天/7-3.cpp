#include <iostream>
#include<string.h>
using namespace std;
int len;
char s1[1000000], s2[10000];
bool vis[200];
int main() 
{
	while (cin.getline(s1, 1000000)) 
	{
		cin.getline(s2, 10000);
		len = strlen(s1);
		memset(vis, 0, 200);
		for (int i = 0; s2[i]; i++)
			vis[int(s2[i])] = 1;
		for (int i = 0; i < len; i++) 
			if (!vis[int(s1[i])])
				putchar(s1[i]);
		puts("");
	}
}