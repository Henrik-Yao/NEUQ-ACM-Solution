#include<iostream>
using namespace std;
#define maxn 10000001
int prime[maxn] = { 0 };
int visit[maxn] = { 0 };
void Prime(int n) 
{
    for (int i = 2; i <= n; i++) {
        //cout << " i = " << i << endl;
        if (!visit[i]) {
            prime[++prime[0]] = i;      //纪录素数， 这个prime[0] 相当于 cnt，用来计数
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= n; j++) {
            //            cout<<"  j = "<<j<<" prime["<<j<<"]"<<" = "<<prime[j]<<" i*prime[j] = "<<i*prime[j]<<endl;
            visit[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    Prime(n);
    cout << prime[0] << endl;
	return 0;
}