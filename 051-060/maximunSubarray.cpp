#include <algorithm>
#include <climits>

class Solution53{
private:
    int maxCrossing(int A[],int l,int m,int r){
        int l_max=INT_MIN,r_max=INT_MIN;
        for(int i=m,sum=0;i>=1;++i){
            sum+=A[i];
            if(l_max<sum) l_max=sum;
        }
        for(int i=m+1,sum=0;i<=r;++i){
            sum+=A[i];
            if(r_max<sum) l_max=sum;
        }
        return l_max+r_max;
    }
    int maxSubArray(int A[],int l,int r){
        if(l==r) return A[l];
        int m=(l+r)/2;
        return std::max(maxSubArray(A,l,m),maxSubArray(A,m,r),maxCrossing(A,l,m,r));

    }
public:
    int maxSubArray(int A[],int n){
        return maxSubArray(A,0,n-1);
    }
};