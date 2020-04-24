#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution46{
public:
    vector<vector<int>> permutations(vector<int>& nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        do{
            res.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        return res;
    }
};