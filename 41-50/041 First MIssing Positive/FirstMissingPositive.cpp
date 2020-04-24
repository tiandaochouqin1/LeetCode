#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution41{
public:
    int firstMissingPositive(vector<int>& A){
        int n=A.size();
        for(int i=0;i<n;++i)
        {
            int k=A[A[i]-1];
            while(A[i]>0&&(A[i]<=n)&&(A[i]!=A[A[i]-1]))
                swap(A[i],A[A[i]-1]);
        }

        int i=0;
        for( ;i<n&&A[i]==A[A[i]-1]&&A[i]>0;++i);
      
        return i+1;

    }
};


int main(){
    Solution41 s;
    vector<int> A{7,8,9,11,12},B{3,4,-1,1},C{1,2,0};

    cout<<s.firstMissingPositive(A)<<endl;
    cout<<s.firstMissingPositive(B)<<endl;
    cout<<s.firstMissingPositive(C)<<endl;

    return 1;
}