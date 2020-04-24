#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        long absN=abs((long) n);
        while(absN>0){
            if((absN&1)==1) ans*=x;//按位与 &-两个操作位都为1则输出为1；按位或|两个操作位都为0则输出为0 
            absN>>=1;
            x*=x;
        }
        return n<0?1/ans:ans;
    }
};