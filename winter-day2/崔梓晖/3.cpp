#include <bits/stdc++.h>
using namespace std;
string hou;
string zhong;
bool pd(string s1,string s2)
{
	int l1=s1.size(),l2=s2.size();
	if(!l1&&!l2)
	return true;
	if(l1!=l2)
	return false;
	char root=s1[l1-1];
	int q;
	for(q=0;q<l2;q++)
	{
		if(s2[q]==root)
		break;
	}
	string s1l=s1.substr(0,q);
    string s1r=s1.substr(q,l1-1-q);
    string s2l=s2.substr(0,q);
    string s2r=s2.substr(q+1);
    for(int i=0;i<s1l.size();i++) 
	{
        if(s2l.find(s1l[i])==s2l.npos) 
		return false;
    }
    for(int i=0;i<s1r.size();i++) 
	{
        if(s2r.find(s1r[i])==s2r.npos) 
		return false;
    }
    return pd(s1l,s2l)&&pd(s1r,s2r);
}
int deep(int root,int s,int e)
{
	if(s<=e)
	{
		int k;
		for(k=s;k<e;k++)
		{
			if(zhong[k]==hou[root])
			break;
		}
		int hl=deep(root-1-e+k,s,k-1); 
		int hr=deep(root-1,k+1,e);
		return max(hl,hr)+1;
	}
	else return -1;
}
void deal(int root,int s,int e)
{
	if(s>e)
	return;
	int k;
	for(k=s;k<e;k++)
	{
		if(zhong[k]==hou[root])
		break;
	}
	cout<<hou[root];
	deal(root-1-e+k,s,k-1);
	deal(root-1,k+1,e);
}
int main()
{
	while(cin>>hou>>zhong)
	{
		if(pd(hou,zhong))
		{
			int n=hou.size();
			cout<<deep(n-1,0,n-1)<<endl;
			deal(n-1,0,n-1);
			cout<<endl;
		}
		else cout<<"INVALID"<<endl;
	}
	return 0;
}
