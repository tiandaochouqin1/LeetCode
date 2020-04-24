#include <iostream>
#include <vector>

using namespace std;

class Solution42{
public:
    int trap(vector<int>& height){
        int l=0,r=height.size()-1;
        int res=0,lm=0,rm=0;
        while(l<r)
        {
            if(height[l]<=rm)
            {
                height[l]>=lm?lm=height[l]:res+=(lm-height[l]);
                l++;
            }
            else
            {
                height[r]>=rm?rm=height[r]:res+=(rm-height[r]);
                r--;
            }
        }
        return res;
    }


    int trappingRainWater(vector<int>& height){
        int b=0,e=0,res=0,i=1;
        for(;i<height.size()-1;++i)
        {
            if(height[i]>height[i-1]&&height[i]>height[i+1])
            {
                b=e,e=i;
                res+=sum(b,e,height);
            }
        }
        res+=sum(e,i,height);
        return res;        
    }

    int sum(int b,int e,vector<int> &height)
    {
        int s=0;
        int k=height[b]>height[e]?height[e]:height[b];
        for(int i=b+1;e-i>0;++i)
        {
            s+=k>height[i]?(k-height[i]):0;
        }
        cout<<b<<'-'<<e<<','<<k<<'='<<s<<endl;
        return s;
    }
};

int main(){
    Solution42 s;
    vector<int> ht{0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<s.trappingRainWater(ht)<<endl<<s.trap(ht)<<endl;

    return 1;
}