#include <iostream>
#include <vector>

using namespace std;
//此算法时间复杂度有问题
class Sol34{    
    int BinarySearch(int A[],int l,int r,int target)
    {
        for(int mid;l<=r;)
        {
            mid=(l+r)>>1;
            if(A[mid]<target) l=mid+1;
            else if(A[mid]>target) r=mid-1;
                else return mid;
           
        }
        return -1;
    } 
public:
    vector<int> FindRange(int A[],int n,int target)
    {
        int pos=BinarySearch(A,0,n-1,target),l=-1,r=-1;
        cout<<"pos="<<pos<<endl;
        if(pos!=-1){
            l=r=pos;
            for(int low=l;(low=BinarySearch(A,1,low-1,target))!=-1;l=low ) ;
            for(int high=r;(high=BinarySearch(A,high+1,n-1,target))!=-1;r=high) ;
        }
        return {l,r};
    }
};

int main(){
    Sol34 s;
    int A[]={1,2,2,3,3,3,4,4,4,4,5};
    
    vector<int> v=s.FindRange(A,11,4);

    for(auto i:v)
        cout<<i<<endl;

    return 1;

}