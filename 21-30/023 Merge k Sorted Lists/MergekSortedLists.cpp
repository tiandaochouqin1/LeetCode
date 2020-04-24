#include "solution.h"
using namespace std;
int main()
{
    Solution s;
    
    
    vector<ListNode *> vec{ 
        s.CreatLinkedList({1,3,5,7,9}),
        s.CreatLinkedList({1,3,5,7,9}),
        s.CreatLinkedList({2,4,6,8,10}),
        s.CreatLinkedList({0,11,12,13,14})      };

    ListNode  *ret = s.MergerKLists(vec);
    s.Print(ret);



    return 0;
}


