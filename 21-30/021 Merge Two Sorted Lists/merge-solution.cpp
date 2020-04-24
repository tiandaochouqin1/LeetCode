#include "solution.h"
#include <iostream>
using std::cout;
using std::endl;

void PrintandClear(ListNode *head)
{
    while (head)
    {
        std::cout<<head->val;
        if (head->next)    std::cout<<"->";
        ListNode *del=head;
        head=head->next;
        delete del;
    }    
    std::cout<<std::endl;
}



int main()
{
    Solution s;
    vector<int> vec1{1,2,3,4,9},vec2{0,2,3,6,7};
    ListNode *l1=s.CreatLinkedList(vec1.begin(),vec1.end());
    
    ListNode *l2=s.CreatLinkedList(vec2.begin(),vec2.end());

    ListNode *ll=s.MergeTwoList(l1,l2);
    // PrintandClear(l1);
    // PrintandClear(l2);
    PrintandClear(ll);

    return 0;

}
