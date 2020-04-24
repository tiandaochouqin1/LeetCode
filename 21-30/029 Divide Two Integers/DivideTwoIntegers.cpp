#include <climits>
#include <iostream>
using namespace std;

class Solution{
public:
    int DivideTwoIntegers(int dividend,int divisor)
    {
        if(dividend==INT32_MIN&&divisor==-1) return INT32_MAX;
        int sign=dividend>0^divisor>0?-1:1;
        int dd=abs(dividend),dr=abs(divisor),ans=0;
        while(dd>=dr)
        {
            long temp=dr,m=1;
            while(temp<<1<=dd){
                temp<<=1;
                m<<=1;            }
            dd-=temp;
            ans+=m;
        }
        return sign>0?ans:-ans;
    }
};

int main()
{
    Solution s;
    cout<<s.DivideTwoIntegers(12312543,4)<<endl<<s.DivideTwoIntegers(-244342423,23)<<endl;

    return 1;
}