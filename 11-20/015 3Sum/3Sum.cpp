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
    vector<vector<int>> threesum(vector<int> &nums){
        set<vector<int>> res;

        sort(nums.begin(),nums.end());
        // for(auto i:nums)
        //     std::cout<<i;

        for(auto iter1=nums.begin();*iter1<=0;++iter1)
        {
            for (auto iter=iter1+1; iter!=nums.end()-1; ++iter)
            {
                
                if(find(iter+1,nums.end(),-*iter1-*iter)!=nums.end()){                    
                    res.insert({*iter1,*iter,-*iter1-*iter});
                    std::cout<<*iter1<<*iter<<-*iter1-*iter<<std::endl;
                }
            }
        }

        return vector<vector<int>> (res.begin(),res.end());

    } 
};

int main(){
    Solution s;
    vector<int> vec{-1,0,-1,1,2,-4};
    
    vector<vector<int>> res=s.threesum(vec);
    // std::cout<<"sfdsf";
    for(auto n:res)
    {
        std::cout<<std::endl;
        for(auto k:n)
            std::cout<<k<<' ';
    }

    // system("pause");
    std::cin.get();
    return 0;
}
