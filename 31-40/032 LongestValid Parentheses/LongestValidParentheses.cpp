#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution{
public:
    int LongestParenthes(string str){
        int left=0,right=0,len=0,maxlen=0;
        for(auto i=0;i<str.size();++i)
        {
            
            if(str[i]=='(')  ++left;
            else if(str[i]=')')  ++right;

            if(right>left) {len=0;right--;}
            else  if(right==left) 
            {                
                len+=left+right;
                left=right=0;
                if(len>maxlen) maxlen=len;
            }   
        }
          for(auto i=str.size()-1;i>-1;--i)
        {
            
            if(str[i]=='(')  ++left;
            else if(str[i]=')')  ++right;
            
            if(right<left) {len=0; left=0;}

            else if(right==left) 
            {                
                len+=left+right;
                left=right=0;
                if(len>maxlen) maxlen=len;
            }   
        }
  

        return maxlen;
    }

    int LongestValidParentheseHeap(string str)
    {
        stack<int> stk;
        int Maxlen=0,len=0,start;
        for(auto i=0;i!=str.size();++i)
        {
            if(str[i]=='(') stk.push(i);
            else if(str[i]==')')
            {
                if(stk.empty()) start=i+1;
                else {
                    stk.pop();//这一步很关键
                    Maxlen=stk.empty()?max(Maxlen,i-start+1):max(Maxlen,i-stk.top());
                }
            }
        }
        return Maxlen;
    }
    //垃圾
    int LongestValidParenthese(string str)
    {
        vector<int> num{0,1};
        stack<char> stk;
        stk.push(str[0]);
        for (size_t i = 1; i < str.size(); i++)
        {
            if(stk.top()=='('&&str[i]==')')
            {
                stk.pop(); 
            }
            else
            {
                stk.push(str[i]);
            }
            num[i+1]=stk.size();
        }
        int k=*prev(num.end());

        int flag=0;
        for(auto i=0;i<num.size();++i)
        {
            if(num[i]<=k)
            {   int j=num.size()-1;
                for(;j>i;--j)
                {
                    if(num[i]==num[j]) break;
                }
                if(j-i>flag) flag=j-i;
            }
        }
        return flag;
    }
};

int main(){
    Solution s;
    string str="())())(()(()()))))()";
    int a=s.LongestParenthes(str);
    int b=s.LongestValidParentheseHeap(str);
    cout<<a<<endl<<b<<endl;

    return 1;
}

