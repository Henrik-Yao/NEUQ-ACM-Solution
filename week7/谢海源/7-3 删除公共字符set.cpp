#include<bits/stdc++.h>
using namespace std;
set<char>s;
int main()
{
	string s1,s2,s3;
	int n1,n2;
	char k;
	while(getline(cin,s1)&&getline(cin,s2))
	{
		s.clear();
	    n1=s1.length();
 	    n2=s2.length();
 	    for(int i=0;i<n2;i++)
 	    {
 	    	s.insert(s2[i]);
		}
	    for(int i=0;i<n1;i++)
	    {
		    if(s.find(s1[i])!=s.end());
		     else cout<<s1[i];//该字符未在s2出现则输出
	    }
	    cout<<endl;
	}
	return 0;	
}
/*They are students.
aeiou*/