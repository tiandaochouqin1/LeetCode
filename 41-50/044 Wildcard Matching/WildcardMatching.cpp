#include <iostream>
using namespace std;

class Solution44{
public:
    bool match(string s,string p)
    {
        int slen=s.size(),plen=p.size();
        int i=0,j=0;
        while(i<slen&&j<plen)
        {                      
            if(s[i]==p[j]||s[j]=='?') 
            { 
                ++i,++j;                  
                continue;
            }
            if(p[j]=='*') 
            {   
                if(p[j+1]==s[i]) j++;
                    else      ++i; 
                continue;
            }
            return false;
        }
        cout<<j<<i<<endl;
        return j==plen?true:false;
    }
};

int main(){
    Solution44 s;
    string str{"abceb"},p{"a*b"};

    cout<<s.match(str,p)<<endl<<endl;

    return 1;
}