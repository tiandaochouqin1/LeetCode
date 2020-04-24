#include <vector>
#include <iostream>
#include <string>
#include <functional>
using std::function;
using std::string;
using std::cout;
using std::cin;
using std::vector;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        function<void (string,int,int)> addParenteses=[&](string str,int l,int r)
        {
            if (l==0&&r==0) vec.push_back(str);            
            if (l>0) addParenteses(str+'(',l-1,r);
            if (r>l) addParenteses(str+')',l,r-1);
            // cout<<str<<std::endl; 
        };

        addParenteses("",n,n);
        return vec;   
    }
};

int main()
{
    Solution s;
    int num;
    cin>>num;
    
    for (auto c:s.generateParenthesis(3))
    {
        cout<<c<<std::endl;
    }
    

    return 1;

}