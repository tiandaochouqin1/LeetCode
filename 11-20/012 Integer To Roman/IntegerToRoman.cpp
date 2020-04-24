#include <string>
#include <map>
#include <iostream>
using std::string;using std::map;using std::cout;


class Solution {
public:
    string intToRoman(int num) 
    {
         std::map<int, string> map = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, 
                                     {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        string ret;
        for (auto iter=map.rbegin();iter!=map.rend();++iter)
            while (num>=iter->first)
            {
                ret+=map[iter->first];
                num-=iter->first;
            }
        return ret;        
    }
};

int main()
{
    Solution s;
    int a=149;
    cout<<s.intToRoman(a);
    return 1;
}