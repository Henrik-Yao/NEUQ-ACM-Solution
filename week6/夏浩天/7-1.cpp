#include<iostream>
#include<string.h>
using namespace std;
char a[1000100], p[1000100];
int cp, ca, nex[1000010], cs;
void nextt()
{
	int j = 0;
	for (int i = 2; i <= cp; i++)
	{
		while (j && p[i] != p[j + 1]) j = nex[j];
		if (p[i] == p[j + 1]) j++;
		nex[i] = j;
	}
}
void kmp()
{
	int j = 0;
	for (int i = 1; i <= ca; i++)
	{
		while (j && a[i] != p[j + 1]) j = nex[j];
		if (a[i] == p[j + 1]) j++;
		if (j == cp) {
			j = nex[j];
			//			printf("%d ",i-cp);
			cs++;
		}
	}
}
int main()
{
	cin >> a + 1 >> p + 1;
	ca = strlen(a + 1);
	cp = strlen(p + 1);
	nextt();
	kmp();
	cout << cs << endl;
}