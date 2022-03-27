#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
		int da;
		Node* nex;
		
		Node(const int val, Node* p=NULL): da(val), nex(p){
		}
		Node(Node* p=NULL):nex(p){
		}
};
int a[999];

int main(void)
{
	int n=0;
	while(cin>>a[n])
		n++;
	sort(a, a+n); 
	
	for(int i=0; i<n; i++)
	{
		cout<<a[i];
		if(i+1!=n)
			cout<<"->";
	}
	cout<<endl;
	int t=0;
	for(int i=0; i<n; i++)
		if(a[i]%2==1)
		{
			if(t)
				cout<<"->";
			cout<<a[i];
			t=1;
		}
	puts("");
	t=0;
	for(int i=0; i<n; i++)
		if(a[i]%2==0)
		{
			if(t)
				cout<<"->";
			cout<<a[i];
			t=1;
		}
	
	return 0;
}