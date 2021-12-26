#include<bits/stdc++.h>
using namespace std;

int solve(string &text,int site){
    vector<char> que;
    char base = text[site+1];
    int s;
    cout << base;
    for(int i=site+2; i<text.size(); i++){
        if(text[i] == ')'){
            s = i;
            break;
        }
        else if(text[i] >= 'a' && text[i] <= 'z'){
            que.push_back(text[i]);
        }
    }
    for(int i=que.size()-1; i>=0; i--){
        cout << que[i] << base;
    }
    return s;
}

int main(){
    string text;
    queue<char> que;
    cin >> text;
    for(int i=0; i<text.size(); i++){
        if(text[i] == 'B'){
            cout << "tsaedsae";
        }
        else if(text[i] == 'A'){
            cout << "sae";
        }
        else if(text[i] == '('){
            i = solve(text,i);
        }
    }
}
