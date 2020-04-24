#include <iostream>
#include <vector>
#include <string>
#include <map>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::map;

#include <stack>
using std::stack;
//Stack Solution
class Solution2{
public:
    bool isValid(string s)
    {
        stack<char> stk;
        for(auto c :s){
            if (!stk.empty()&&((c==')'&&stk.top()=='(')||(c==']'&&stk.top()=='[')||(c=='}'&&stk.top()=='{'))) 
            stk.pop();
           else stk.push(c);
        }
        return stk.empty();
    }
};

class Solution
{
public:
    bool isValid(string s)
    {
        vector<char> vec;
        map<char,char> mp{{'(',')'},{'[',']'},{'{','}'}};
        vec.push_back(s[0]);
        for (size_t i = 1; i < s.size(); i++)
        {
            if (mp[*(vec.end()-1)]==s[i])
                vec.pop_back();
            else
                vec.push_back(s[i]);            
        }
        // cout<<vec.size();
        return vec.size()==0?1:0;
    }
};

int main()
{
    Solution2 s;
    string str1,str2;
    cin>>str1;
    cout<<endl<<(s.isValid(str1)==1?"valid":"invalid")<<endl;
    cin>>str2;
    cout<<endl<<(s.isValid(str2)==1?"valid":"invalid")<<endl;

    return 0;
}