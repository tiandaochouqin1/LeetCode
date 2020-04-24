#include  <map>
#include <string>
using std::string;
using std::map;
#include  <algorithm>
using std::max;
// using namespace std;

class Solution {
public: 
    int lengthOfLongestSubstring(string s) 
    {
        map<char,size_t> mp; 
        size_t maxNum=0,lastRepeatPos=0;

        for(size_t i=0;i<=s.size();++i)
        {
            auto found=mp.find(s[i]);
            if(found!=mp.end()&& found->second >=lastRepeatPos)
            {
                maxNum=max(maxNum,i-lastRepeatPos);
               lastRepeatPos=found->second+1;
            }   
            mp[s[i]]=i;
        }
        return max(maxNum,s.size()-lastRepeatPos);
    }
};