#include<bits/stdc++.h>
using namespace std;
int max1=-1;
bool judge(string a, string b) { 
    if (a.length() == 0 && b.length() == 0)
        return true;
    if (a.length() != b.length())
        return false;
    char ch = a[a.length() - 1];
    int i;
    for (i = 0; i < b.length(); i++) {
        if (ch == b[i])
            break;
    }
    string aleft = a.substr(0, i);
    string aright = a.substr(i, a.length() - 1 - i);
    string bleft = b.substr(0, i);
    string bright = b.substr(i + 1);
    for (i = 0; i < aleft.length(); i++) {
        if (bleft.find(aleft[i]) == -1)
            return false;
    }
    for (i = 0; i < aright.length(); i++) {
        if (bright.find(aright[i]) == -1)
            return false;
    }
    return judge(aleft, bleft) && judge(aright, bright);
}
void preorder(string m,string l,int floor)
{
	max1=max(max1,floor);
	int len;
	len=l.length();
	if(len==0) return;
	if(len==1)
	{
		cout<<m[0];
		return ;
	}
	int pos=m.find(l[len-1]);
	cout<<l[len-1];
	preorder(m.substr(0,pos),l.substr(0,pos),floor+1);
	preorder(m.substr(pos+1,len-1-pos),l.substr(pos,len-1-pos),floor+1);
}
void geth(string m,string l,int floor)
{
	max1=max(max1,floor);
	int len;
	len=l.length();
	if(len==0) return;
	if(len==1)
	{
//		cout<<m[0];
		return ;
	}
	int pos=m.find(l[len-1]);
//	cout<<l[len-1];
	geth(m.substr(0,pos),l.substr(0,pos),floor+1);
	geth(m.substr(pos+1,len-1-pos),l.substr(pos,len-1-pos),floor+1);
}
int main()
{
	string mid,last;
	while(cin>>last>>mid)
	{
		max1=-1;
		if(judge(last,mid)==false)
		{
			cout<<"INVALID"<<endl;
			continue;
		}
		geth(mid,last,0);
		cout<<max1<<endl;
		preorder(mid,last,0);
		
		cout<<endl;
	}
	
}
