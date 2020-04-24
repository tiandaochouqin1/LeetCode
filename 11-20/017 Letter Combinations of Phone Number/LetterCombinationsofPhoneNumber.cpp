#include <iostream>
#include <vector>
#include <string>
#include <array>

using std::vector;
using std::array;
using std::string;
using std::cout;
using std::cin;
using std::endl;

class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        array<string,10> map{"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
         vector<string> res{""};
         for (auto digit:digits)
         {
             vector<string> tmp;
             for(auto c:map[digit-'0'])
             {
                 for(auto &pre:res)
                 {
                    tmp.push_back(pre+c);
                 }
             }
             res=tmp;
         }
         
        return res;
    }
};

int main()
{
    string s1;
    cin>>s1;
    Solution sol;
    vector<string> str=sol.letterCombinations(s1);
    for(auto c:str)
        cout<<c<<',';
    return 1;

}