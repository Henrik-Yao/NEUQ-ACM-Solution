#include <bits/stdc++.h>
using namespace std;
class iinput
{
    private:
    vector<char>chain;
    bool is;
    int index;
    public:
    iinput()
    {
        is=false;
        index=0;
    }
    void mhome(){index=0;}
    void mend(){index=chain.size();}
    void mleft(){if(index-1>=0)index--;}
    void mright(){if(index+1<=chain.size())index++;}
    void changeis(){is=!is;}
    void backspace(){if(chain.size()>0){chain.erase(chain.begin()+index-1);index--;}}
    void in(char c)
    {
        if(index==chain.size()-1)chain.push_back(c);
        else if(is)chain[index]=c;
        else chain.insert(chain.begin()+index,c);
        index++;
    }
    string ttstring()
    {
        string s;
        for(const char& c:chain) s.push_back(c);
        return s;
    }
    void operator>>(const char& c)
    {
        if(c=='[')mhome();
        else if(c==']')mend();
        else if(c=='{')mleft();
        else if(c=='}')mright();
        else if(c=='-')changeis();
        else if(c=='=')backspace();
        else in(c);
    }
};
int main()
{
    string s;
    getline(cin,s);
    iinput kk;
    for(const char& c:s)kk>>c;
    cout<<kk.ttstring()<<endl;
    
    return 0;
}