#include<bits/stdc++.h>

using namespace std;
bool num[10000009];
int Num;
void Eratosthenes(int n)
{
    for (int i=2; i<=n; i++) {
        if (num[i]) {

            Num++;
            for (int j=i; j<=n; j+=i) {
                num[j]=false;
            }
        }
    }

}
int main()
{
    int n;
    cin>>n;
    for (int i=2; i<=n; i++) {
        num[i]=true;
    }
    Eratosthenes(n);
   cout<<Num<<endl;

}
