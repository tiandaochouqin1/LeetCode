#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) 
    {
        for (char c=*p;c!='\0'; ++s,c=*p) //s自增
        {
           if (p[1]!='*') ++p;//非*,p自增
           else if (isMatch(s,p+2)==1) return true; //为*时不自增，继续使用同一个p进行比较;同时考虑*代表0次的情况
           
           if(!(c==*s||c=='.'&&*s!='\0')) return false ;    //进行比较
        }
        return *s=='\0';    //匹配到末尾，即完整匹配           
    }
};

int main()
{
    Solution s;
    string a1,b1;
    const char* a,*b;
    for(int i=0;i!=3;++i)
    {
        
    cout<<"Input a word"<<endl;
    cin>>a1;

    cout<<"Input a expression"<<endl;
    cin>>b1;
    a=a1.c_str();
    b=b1.c_str();
    cout<<s.isMatch(a,b)<<endl;

    }
}