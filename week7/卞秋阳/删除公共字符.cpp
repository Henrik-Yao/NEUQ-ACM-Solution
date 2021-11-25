#include<bits/stdc++.h>
using namespace std;
int main()
{ 
 string a;
string b;
while(getline(cin,a),getline(cin,b))
{
	int	m=a.length();
	int	n=b.length();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++){
				if(a[j]==b[i])
				{
					a.erase(j--,1);
				}
			}
		}
		cout<<a<<endl;
}

}
