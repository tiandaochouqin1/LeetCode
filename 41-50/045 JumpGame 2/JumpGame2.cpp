#include <iostream>
#include <vector>
using namespace std;

class Solutioin45{
public:
    int jump(vector<int>& nums)
    {
        int start=0;
        int end=0;
        int cnt=0;
        int nextEnd=0;
        //贪婪算法，[start,end]  [end,nextEnd]分别表示第i次，i+1次跳跃到达的区间.
        //迭代到区间包含终点元素
        for(int i=0;i<nums.size();++i)
        {
            if((i>end)) {return -1;}
            nextEnd=max(nextEnd,i+nums[i]);
            if(i==end)
            {
                start=i+1;
                end=nextEnd;
                cnt++;
            }
        }
        return cnt;
    }
};

