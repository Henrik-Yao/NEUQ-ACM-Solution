#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int pre[N];

int main(){
    string text,pat;
    cin >> text >> pat;
    int len_t = text.size(),len_p = pat.size();
    pre[0] = -1,pre[1] = 0;
    for(int i=1,j=0; i<len_p-1; i++){
        while(j && pat[i] != pat[j]){
            j = pre[j];
        }
        if(pat[i] == pat[j])    j++;
        pre[i+1] = j;
    }
//    for(int i=0; i<len_p; i++){
//    	cout << pre[i] << endl;
//	} 
    int cnt = 0;
    int i=0,j=0;
    while(i<len_t){
    	if(j == len_p - 1 && text[i] == pat[j]){
            cnt++;
            j = pre[j];
        }
        if(pat[j] == text[i])   i++,j++;
        else{
            j = pre[j];
            if(j == -1)
                i++,j++;
        }
	}
    cout << cnt;
    return 0;
}
