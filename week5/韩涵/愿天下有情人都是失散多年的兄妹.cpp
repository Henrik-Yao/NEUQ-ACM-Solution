#include<iostream>
using namespace std;

bool judge = 0;
bool jud[200005];
int elem, fu[200005], mu[200005];
char sex[200005];

void relative(int n, int era)
{
	if (era > 5 || n == -1 || n == 0) return;
	if (jud[n]) judge = 1;
	jud[n] = 1;
	relative(fu[n], era + 1);
	relative(mu[n], era + 1);
	return;
}

int main()
{
	int n;
	cin >> n;
	while (n--) cin >> elem >> sex[elem] >> fu[elem] >> mu[elem];
	int k, male, female;
	cin >> k;
	while (k--)
	{
		cin >> male >> female;
		if (sex[male] == sex[female])
		{
			cout << "Never Mind" << endl;
			continue;
		}
		memset(jud, 0, sizeof(jud));
		relative(male, 1);
		relative(female, 1);
		if (!judge) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}