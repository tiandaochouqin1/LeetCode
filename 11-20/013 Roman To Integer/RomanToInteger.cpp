#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int romanToInt(string s) 
    {
        int res=0;
        for (auto iter=s.rbegin(); iter!=s.rend(); ++iter)
        {
            switch (*iter)
            {
            case 'I': res+=res>=5?-1:1; break;
            case 'V': res+=5; break;
            case 'X': res+=10*(res>=50?-1:1); break;
            case 'L': res+=50; break;
            case 'C': res+=100*(res>=500?-1:1); break;
            case 'D': res+=500; break;
            case 'M': res+=1000; break;
            }
           
        }
         return res;
    //     int num=0;
    //     for(auto i=0;i<s.size();++i)
    //     {
    //         switch (s[i])
    //         {
    //         case 'I':
    //             {
    //              if (s[i+1]=='V')
    //             {   num+=4;
    //                 ++i; }
    //             else if(s[i+1]=='X') 
    //             {   num+=9;
    //                 ++i;  }
    //             else
    //             {   num=num+1;
    //             }
    //                 break;
    //             }
    //         case 'V':
    //             { num=num+5;
    //                 break;}
    //         case 'X':
    //              {   if (s[i+1]=='L')
    //             {
    //                 num+=40;
    //                 ++i;
    //             }
    //             else if(s[i+1]=='C')
    //             {   num+=90;
    //                 ++i;
    //             }
    //             else
    //             {
    //             num+=10;
    //             }
    //                 break;}
    //         case 'L':
    //            { num+=50;
    //             break;}
    //         case 'C':
    //             { 
    //              if (s[i+1]=='D')
    //             {num+=400;
    //                 ++i;}
    //             else if(s[i+1=='M'])
    //             {num+=900;
    //                 ++i;}
    //             else
    //             num+=100;        
    //             break;}
    //         case 'D':
    //          {   num=num+500;
    //             break;}
    //         case 'M':
    //          {   num=num+1000;
    //             break;}
                  
    //         default:
    //            { break;}
    //         }

    //     }
    //     return num;
    }
};

int main()
{
    Solution sol;
    vector<string> vec={"III","IV","IX","LVIII","MCMXCIV"};
    
    for (auto vb=vec.begin(); vb!=vec.end();++vb)
    {
    cout<<*vb<<'='<<sol.romanToInt(*vb)<<endl;
    }    
    // cout<<sol.romanToInt("MCM")<<endl;
    return 1;
}