#include<bits/stdc++.h>
using namespace std;
struct student
{
    int score;
    char name[21];
};
int main()
{
    student s[21],temp;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>s[i].name>>s[i].score;
	}
    for(int i=1;i<n;i++)
	{
        for(int j=0;j<n-i;j++)
		{
            if(s[j].score<s[j+1].score)
			{
                temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
            }
            if(s[j].score==s[j+1].score&&strcmp(s[j].name,s[j+1].name)>0)
			{
                temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp; 
            }
        }
    }
    for(int i=0;i<n-1;i++)
    {
    	cout<<s[i].name<<" "<<s[i].score<<endl;
	}
	cout<<s[n-1].name<<" "<<s[n-1].score;
    return 0;
}
