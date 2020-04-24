#include <vector>
#include <iostream>
using namespace std;
class Solution{
public:
    vector<int> nextPermutaion(vector<int>& vec)
    {
        vector<int>::iterator v1=prev(vec.end()),v2=vec.end()-1;
        int tmp;
        for(;(v1-1)!=vec.begin()&&*(v1-1)>*v1;--v1) ;
        if(!(v1-1==vec.begin()&&*(v1-1)>*v1))//iter_swap(v1-1,v2)
         {   tmp=*(v1-1);
            *(v1-1)=*v2;
            *v2=tmp;}
        for(;v1<v2;++v1,--v2)//reverse(v1,v2)
        {   tmp=*v1;
            *v1=*v2;
            *v2=tmp;
        }
        return vec;
    }
};

int main()
{
    Solution s;
    vector<int> v{1,2,3};
    vector<int> res=s.nextPermutaion(v);
    for(auto i:res)
        cout<<i<<" ";
    return 1;
}