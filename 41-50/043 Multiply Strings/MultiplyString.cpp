#include <iostream>
#include <algorithm>
using namespace std;

class Solution43{
public:
    string multiplyString(string s1,string s2)
    {
        string res(s1.size()+s2.size(),'0');

        for(int i=s1.size()-1;i>=0;--i)
        {   int carry=0;
            for(int j=s2.size()-1;j>=0;--j)
            {
                int sum=(s1[i]-'0')*(s2[j]-'0')+(res[i+j+1]-'0')+carry;///i+j+1 为res的最后一位
                carry=sum/10;
                res[i+j+1]=sum-carry*10+'0';
            }
            res[i]+=carry;
        }
        size_t pos=res.find_first_not_of('0');
        return pos!=string::npos?res.substr(pos):"0";
    }
};

int main()
{
    Solution43 s;
    string s1{"123"},s2{"223"};
    cout<<s.multiplyString(s1,s2)<<endl;
    return 1;
}