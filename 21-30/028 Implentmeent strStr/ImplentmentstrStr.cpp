#include <iostream>
using namespace std;

class Solution{
public:
    int strStr(string haystack,string needle)
    {
        for(auto i=0;i<haystack.size()-needle.size()+1;++i)
        {   
            int k=0;
            for(auto j=i;k!=needle.size()&&(haystack[j]==needle[k]);++j,++k)               {}
            if(k==needle.size()) return i;
        }
        return -1;
    }
};
//注意文件路径不要有特殊字符！！！！！！
int main()
{
    Solution s;
    string h1{"hello"},h2{"aaaa"},n1{"ll"},n2{"bba"};
    cout<<s.strStr(h1,n1)<<endl<<s.strStr(h2,n2)<<endl;
    return 1;
}