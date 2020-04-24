#include <string>
#include <iostream>

using namespace std;


void longestP(const string& s,int left,int right,int& start,int& end)
{
    int   n=s.size();
    while(left>=0&&right<n&&s[left]==s[right])
        --left,++right;
    ++left,--right;
    if(right-left>end-start)
    {
        end=right;
        start=left;
    }

}

class Solution {
public:
    string longestPalindrome(string s)
    {
        int n=s.size();
        if(n<=1)
            return s;
        int start=0,end=0;
        for(int i=0;i<n-1;++i)
        {
            longestP(s,i,i,start,end);
            longestP(s,i,i+1,start,end);
        }
        return s.substr(start,end-start+1);
    }
};


int main()
{
    string str;
    cin>>str;
    Solution s;
    cout<<s.longestPalindrome(str)<<endl;
    return 0;

}