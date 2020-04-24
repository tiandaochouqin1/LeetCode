#include  <algorithm>
#include <vector>
#include <limits.h>
#include <iostream>
using namespace std;


 class Solutioin
{
  
  public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
     {
        int n = nums1.size();
        int m = nums2.size();
        if(n < m)   //保证数组1一定最长
            return findMedianSortedArrays(nums2,nums1);
        int L1,L2,R1,R2;//边界值
        int c1,c2=0;
        int low = 0, hi = 2*n;  //我们目前是虚拟加了'#'所以数组1是2*n长度
        while(low <= hi)   //二分
        {//实际上是求序号hc1 c2两个划分数组，且保证划分后左右两部分元素个数相同
            c1 = (low+hi)/2;  //初始为m+n,不断减小;数组1左边的个数、 数组1的中间
            c2 = m+n- c1;//初始为0,不断增大;数组2左边元素的个数、总和为m+n
            //根据划分点取得四个中间点的值
            L1 = (c1 == 0)?INT_MIN:nums1[(c1-1)/2];   //map to original element
            R1 = (c1 == 2*n)?INT_MAX:nums1[c1/2];

            L2 = (c2 == 0)?INT_MIN:nums2[(c2-1)/2];
            R2 = (c2 == 2*m)?INT_MAX:nums2[c2/2];

            if(L1 > R2)//短数组1较大，可以舍弃数组右边一半，
                hi = c1-1;
            else if(L2 > R1)//长数组较大，左边一半，c1个
                low = c1+1;
            else
                break;//不满足上面两个条件时则找到了结果
        }
        return (max(L1,L2)+ min(R1,R2))/2.0;
    }
};

int main() {
    Solutioin s;
    vector<int> v1={1,2,4,9};
    vector<int> v2={1,5,6,7,11,13};
    cout<<s.findMedianSortedArrays(v1,v2);
    return 0;

}