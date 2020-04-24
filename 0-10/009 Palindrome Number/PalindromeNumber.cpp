#include <iostream>
using namespace std;
class Solution
{
public:

    bool BetterSolution(int x){
        long rev{0},origin{x};
        if(x<0) return false;
        do
        {
            rev=rev*10+x%10;
        } while (x/=10);
        return rev==origin;
        
    }
    bool PalindromeNumber(int x){
        int a=x,k=0,pop;
        if(a<0) return 0;
        while (a)
        {
            pop=a%10;
            // cout<<pop<<' '<<a<<endl;
            k=k*10+pop;
            a/=10;
        }
        return k==x;  
    }
};
int main(){
    Solution s;
    int x;
    cin>>x;
    cout<<s.PalindromeNumber(x)<<"  "<<s.BetterSolution(x)<<endl;


    return 1;
}