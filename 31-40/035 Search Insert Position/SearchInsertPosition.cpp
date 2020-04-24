#include <iostream>
#include <vector>
using namespace std;
class Solution35{
public:
    int InsertPosition(vector<int>&nums,int target)
    {   int m=nums.size()/2;
        for(int b=0,e=nums.size()-1;b<=e&&nums[m]!=target;m=(b+e)/2)
            nums[m]>target?e=m-1:b=m+1;
        return nums[m]!=target?m+1:m;
    }
};

int main()
{
    Solution35 s;
    vector<int> v{1,3,5,6};
    cout<<s.InsertPosition(v,7)<<endl;

    return 1;
}