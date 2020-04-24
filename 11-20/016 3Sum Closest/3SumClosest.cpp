#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using std::set;
// using std::unique;
using std::find;
using std::vector;
using std::sort;


class Solution {
public:
    int threeSumClosest(vector<int>& nums,int target){
        set<vector<int>> res; //use Set to eliminate the duplicate
        sort(nums.begin(),nums.end());
        // for(auto i:nums)
        //     std::cout<<i;
        int min{INT32_MAX},sum{0},tmpsum{0} ;
        for(auto iter1=nums.begin();iter1!=nums.end()-2;++iter1)
        {
            for (auto b=std::next(iter1),e=std::prev(nums.end()); b!=e; tmpsum>target?--e:++b)
            {
                if(( tmpsum = *iter1 + *b+ *e ) == target)     return target;
                else if (std::abs(tmpsum-target)<min) 
                {   sum=tmpsum;
                    min=std::abs(target-tmpsum);                  
                    std::cout<<'result='<<min<<std::endl;
                }  
            }
        }
        return sum;
    } 
};

int main(){
    Solution s;
    vector<int> vec{-1,2,1,-4};
    
    int res=s.threeSumClosest(vec,0);
    // std::cout<<"sfdsf";
    std::cout<<"Result="<<res<<std::endl;

    std::cin.get();
    return 0;
}
