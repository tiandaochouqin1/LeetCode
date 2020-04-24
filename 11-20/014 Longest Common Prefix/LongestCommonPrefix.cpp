#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if(strs.empty()) return "";
        for (size_t i = 0; i < strs.front().size(); ++i)
        {
            for(const auto  &str:strs)
                if(i==str.size()||str.at(i)!=strs.front().at(i))
                    return strs.front().substr(0,i);   
        }
        return strs.front();  
    }
};

int main() {
    Solution s;
 
    vector<string> str={"flower","flow","flight"};
    std::cout<<s.longestCommonPrefix(str)<<std::endl;
    vector<string> str2={"dog","racer"};
    std::cout<<s.longestCommonPrefix(str2)<<std::endl;


    return 1;
}