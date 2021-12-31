#include <bits/stdc++.h>
using namespace std;
list<int>l1,l2;
int main()
{
	int n,num;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num);
		l1.push_back(num);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num);
		l2.push_back(num);
	}
	l1.sort();
	l2.sort();
	l1.merge(l2);
	int sz=l1.size();
	int i=(sz+1)/2-1;
	list<int>::iterator it=l1.begin();
	while(i--){it++;}
	printf("%d\n",*it);
	return 0;
}
