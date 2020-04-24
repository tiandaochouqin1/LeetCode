#include <iostream>
#include "../023 Merge k Sorted Lists/solution.h"

using namespace std;



class Solution0 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *newhead=new ListNode(-1);
        newhead->next=head;
        for (ListNode *p1=newhead,*p2=head;p2&&p2->next;p1=p2,p2=p2->next)
        {
            p1->next=p2->next;
            p2->next=p1->next->next;
            p1->next->next=p2;
        }
        return newhead->next;
    }
};

int main()
{
    Solution0 s0;
    Solution s;
    s.Print(s0.swapPairs(s.CreatLinkedList({1,2,3,4,5,6,7,8})));
    return 1;


}