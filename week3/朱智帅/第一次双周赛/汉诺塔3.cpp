#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<list>
#include<queue>
#include<stack>
#include<string.h>
#include<vector>
using namespace std;
long long Han[10000001];
int main()
{
	int i,n;
	Han[1] = 2;
	for (i = 2; i < 37; i++)
		Han[i] = 3 * Han[i - 1] + 2;
    while(cin>>n){
    cout<<Han[n]<<endl;
    }
	return 0;
}