#include <iostream>
using namespace std;

class Solution38{
public:
    string CountAndSay(int n)
    {
        if(n==0) return "";
        if(n==1) return "1";
        string res{"1"};
        while(--n){
            string tmp="";
            for(auto  i=0;i<res.size();++i)
            {
                int count=1;
                while(res[i+1]==res[i]&&i<res.size()-1)  count++, ++i;
                tmp+=to_string(count)+res[i];
            }
            res=tmp;
        }
        return res;
    }

    string CountAndSayReverse(int n)
    {
        if(n==0) return "";
        if(n==1) return "1";
        string res=CountAndSayReverse(n-1);
        string tmp="";
        
        for(auto i=0;i<res.size();++i)
        {   int count=1;
            while(res[i+1]==res[i]&&i<res.size()-1) count++,++i;
            tmp+=to_string(count)+res[i];
        }
        return tmp;
    }
    string CountAndSayVector(int n)
    {
        string res="1";
        for(int i=0;i<n-1;++i)
        {
            string tmp;
            auto b=res.begin();
            for(auto e=b;e!=res.cend();++e)
                if(*b!=*e) {tmp+=to_string(e-b)+*b;b=e;}
            res=tmp+to_string(res.cend()-b)+*b;

        }
        return res;
    }
};

int main()
{
    Solution38 s;
    cout<<s.CountAndSay(10)<<endl;
    cout<<s.CountAndSayReverse(10)<<endl;
    cout<<s.CountAndSayVector(10)<<endl;

    return 1;
}