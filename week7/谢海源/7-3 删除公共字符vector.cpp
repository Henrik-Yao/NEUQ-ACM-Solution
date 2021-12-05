#include<bits/stdc++.h>
using namespace std;
vector<char>s;
int main()
{
	string s1,s2,s3;
	int n1,n2,n3,f;
	char k;
	while(getline(cin,s1)&&getline(cin,s2))
	{
		s.clear();
	    n1=s1.length();
 	    n2=s2.length();
 	    for(int i=0;i<n2;i++)
 	    {
 	    	s.push_back(s2[i]);
		}
	    f=1;
	    sort(s.begin(),s.end());
	    vector<char>::iterator x=unique(s.begin(),s.end());
	    s.erase(x,s.end());
	    for(int i=0;i<n1;i++)
	    {
	    	f=1;
	    	for(auto &k:s)
	    	{
	    		if(k==s1[i])
	    		{
	    			f=0;
	    			break;
				}
			}
			if(f==1) cout<<s1[i];
	    }
	    cout<<endl;
	}
	return 0;	
}
/*They are students.
aeiou*/