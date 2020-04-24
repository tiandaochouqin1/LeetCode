#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution011 {
public:
    int maxArea(vector<int>& height) {
        int num{0};
        for (auto beg=height.begin(),end=prev(height.end());end>beg;*beg<*end?++beg:--end)
        {
            num=max(num,static_cast<int>((end-beg)*min(*beg,*end)));//显示转换static_cast<int>，良性转换，风险低
           
        }
        return num;
    }

};

int main() {
    Solution011 s;

    vector<int>  v1={1,8,6,2,5,4,8,3,7};

    cout<<s.maxArea(v1)<<endl;
    

    return 1;
}