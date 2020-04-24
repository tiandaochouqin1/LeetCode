#include <iostream>

using namespace std;

class Solution{
    public :
    int reverse(int x)
    {
        //Can also use the ; long rev;and judge int overfolws at the end
        int rev=0,pop=0;
        while(x!=0)
        {
            pop=x%10;
            x=x/10;
            if(rev>INT32_MAX/10||(rev==INT32_MAX/10&&pop>7)) return 0;
            if(rev<INT32_MIN/10||(rev==INT32_MIN/10&&pop<-8)) return 0;
            rev=rev*10+pop;

        }
        return rev;

    }
};

int main()
{
    Solution s;
    int a,b;
    cin>>a;
    cout<<s.reverse(a)<<endl;
    cin>>b;
    cout<<s.reverse(b)<<endl;

    return 1;

}