#include <iostream>
#include <vector>

using namespace std;
//第一步将问题分解成简单的两个问题
class Solution34{
public:
    vector<int> FindRange(vector<int>& nums,int target)
    {
        int len=nums.size();
        cout<<len<<endl;
        vector<int> v{-1,-1};
        int mid=len/2;
        //找出target，并作为分割点，找不到则结束
        for(auto b=0,e=len;b<=e&&nums[mid]!=target;mid=(b+e)/2){ 
            nums[mid]>target?e=mid-1:b=mid+1;
            // cout<<mid<<endl;
        }
        if(nums[mid]!=target) return v;
        //将分割后的两部分分别进行二分查找，
        else{
            int mid1=mid/2,mid2=(len+mid)/2;

            for(auto b=0,e=mid;b<=e;mid1=(b+e)/2)
            {   if(nums[mid1]<target) b=mid1+1;
                else    e=mid1-1;
                cout<<mid1<<'.'<<endl;
            }
            if(mid1==0) mid1--;
            v[0]=mid1+1;

            for(auto b=mid,e=len;b<=e;mid2=(b+e)/2)
            {   if(nums[mid2]>target) e=mid2-1;
                else    b=mid2+1;
                cout<<mid2<<','<<endl;
            }
            if(mid2==len) mid2--;
            v[1]=mid2;
            
            return v;
        }
    }
};

int main(){
    Solution34 s;
    vector<int> nums{5,5,7,8,8,8,11,12,13,13};
    vector<int> res=s.FindRange(nums,5);
    for(auto i:res)
        cout<<i<<endl;

    return 1;
}