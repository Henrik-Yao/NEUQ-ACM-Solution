#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    string s;
    cin>>s;

    int lens = s.length();


    for(int t=1;t<=n;t++)
    {
        string mo;
        //mo.clear();
        cin>>mo;

        int num=0;

        int lenmo = mo.length();

        for(int i=0;i<=lens-lenmo;i++)
        {
            string temp;

            for(int j=i;j<=i+lenmo-1;j++)
            {
                temp += s[j];

            }
            if(temp == mo)
                    num++;
        }

        cout<<num;
        if(t!=n)
            cout<<endl;

    }


    return 0;
}
