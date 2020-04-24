#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size=1;
        for(size_t n=nums.size(),i=1;i!=n;++i){
            if(n<2) return n;         
            if(nums[i]!=nums[i-1]){
                nums[size++]=nums[i];
            }
        }
        
        return size;
        
    }
};

int main()
{
    Solution s;
    vector<int> nums{1,1,2,3,3,3,5,6,6};
    for (auto n:nums)  {  cout<<n<<'-'; }
    cout<<s.removeDuplicates(nums)<<endl;
    for (auto n:nums)  {  cout<<n<<'-'; }
    return 1;
}