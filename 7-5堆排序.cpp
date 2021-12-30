#include<bits/stdc++.h> 
using namespace std;
vector<int>vec;
int n,i;
void print(vector<int> &vec)
{
	for(i=0;i<n;i++)
		cout<<vec[i]<<' ';
	cout<<endl;
}

int main()
{
	cin>>n;
	for(i=0;i<n;i++)
	{
		int x;
		cin>>x;
		vec.push_back(x);
	} 
	make_heap(vec.begin(),vec.end(),less<int>());
	print(vec);
	for(i=0;i<n;i++)
	{
		pop_heap(vec.begin(),vec.end(),less<int>());
		vec.pop_back();
		print(vec);
	}
	return 0;
}
