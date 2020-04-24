#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int RemoveElement(vector<int> &nums,int k)
    {
        int size=0;
        for (size_t i = 0; i < nums.size(); ++i)
            if (nums[i]!=k) 
                nums[size++]=nums[i];
        return size;
    }
};

int main()
{
    Solution s;
    vector<int> vec{1,2,3,4,5,5,5,6,7};
    int a =s.RemoveElement(vec,5);
    cout<<a<<endl;
    for (size_t i = 0; i < a-1; ++i)
        cout<<vec[i]<<"->";
    cout<<vec[a-1]<<endl;
    return 1;
}