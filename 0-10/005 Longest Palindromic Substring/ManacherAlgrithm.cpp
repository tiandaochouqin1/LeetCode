#include <iostream>
#include <string>
#include <vector>
//#include <algorithm>
using namespace std;

class Solution 
{
public:
    string manacher(string s) 
    {
        //
        string t="$#";
        for(int i=0;i<s.size();++i)
        {
            t+=s[i];
            t+="#";           
        }
        vector <int> p(t.size(),0);
        int mx=0,id=0,len=0,center=0;//mx是回文串能延伸到的最右边的位置。id为mx对应的中心点
        for(int i=0;i<t.size();++i)
        {
            p[i]= mx>i ? min(p[2*id-i],mx-i):1;//p数组是存储回文串长度
        
            while(t[i+p[i]]==t[i-p[i]]) //判断左右元素相等
                ++p[i];

            if(i+p[i]>mx)//更新最右位置mx和对应中心id
            {
                mx=p[i]+i;
                id=i;
            }
            if(p[i]>len)//记录最长的值
            {
                len=p[i];
                center=i;
            }
        }
        return s.substr((center-len)/2,len-1);
    }
};

int main()
{
    Solution sol;
    string s1,s2;
    cin>>s1;
    cout<<sol.manacher(s1)<<endl;
    cin>>s2;
    cout<<sol.manacher(s2)<<endl;

    return 0;

}