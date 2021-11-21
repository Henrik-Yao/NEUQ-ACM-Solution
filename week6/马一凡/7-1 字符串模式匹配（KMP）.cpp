#include<iostream>
#include<cstring>
using namespace std;

string ss,cc;
int next[1000100];
int sum;

void get_next()
{
	int i=0; 
	int l=-1;
    next[0]=-1;
    while (i<cc.size()){
        if (l == -1 || cc[i] == cc[l]){
            i++;
			l++;
            next[i] = l;
        }
        else l = next[l];
    }
    return;
}

int get_kmp()
{
    int i=0;
	int l=0;
    int t=0;
    get_next();
    while (i<ss.size()){
        if (l == -1 || cc[l] == ss[i]){
            i++;
			l++;
		}
        else l = next[l];
        if (l == cc.size())
        {
            l = next[l];
            t++;
        }
    }
    
    
    return t;
}


int main()
{
    cin >> ss;
    cin >> cc;
    sum = get_kmp();
    cout << sum << endl;

    return 0;
}

