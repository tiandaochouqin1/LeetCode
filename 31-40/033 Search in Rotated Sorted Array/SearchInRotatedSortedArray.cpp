#include <vector>
#include <iostream>
using namespace std;
class Solution{
public:
    int SearchRotatedArray(vector<int>& vec,int target){
        int b=0,e=vec.size()-1;
        int m;
        while(b<=e)
        {
            m=(b+e)/2;
            if(vec[m]==target) return m;
            // if(vec[b]==target) return b;
            // if(vec[e]==target) return e;
            if(vec[b]<vec[m]) 
            {
                if(vec[b]<=target&&vec[m]>=target) e=m-1;
                else b=m+1;
            }
            else 
            {
                if(target<=vec[m]||target>=vec[b]) e=m-1;
                else b=m+1;
            }
        }
        return vec[m]==target?m:-1;
    }
};

int main()
{
    Solution s;
    vector<int> v1{4,5,6,7,0,1,2,3};
    cout<<s.SearchRotatedArray(v1,4)<<endl;

    return 1;
}