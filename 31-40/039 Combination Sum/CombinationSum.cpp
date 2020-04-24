#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution39{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates,int target)
    {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> combination;
        combinationSum(candidates,target,res,combination,0);
        return res;
    } 
private:
    void combinationSum(vector<int>& candidates,int target,vector<vector<int>>& res,vector<int> combination,int begin)
    {
        if(!target) { res.push_back(combination);return;}
        for(int i=begin;i!=candidates.size()&&target>=candidates[i];++i)
        {
            combination.push_back(candidates[i]);
            combinationSum(candidates,target-candidates[i],res,combination,i);
            combination.pop_back();
        }
    }
};

int main()
{
    Solution39 s;
    vector<int> v{2,3,5,7};
    int target=8;
    vector<vector<int>> comb=s.combinationSum(v,target);
    for(auto &v1:comb)
        { 
            for(auto i:v1)
                cout<<i<<',';
            cout<<endl;
        }
    
    return 1;

}