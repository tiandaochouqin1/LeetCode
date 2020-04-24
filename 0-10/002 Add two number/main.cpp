#include <iostream>
#include "AddTwoNum.h"
using namespace std;

ListNode *creat_linkedlist(std::initializer_list<int> lst)
{
   auto iter=lst.begin();
   ListNode *head= lst.size()?new ListNode(*iter++):NULL;
   for(ListNode *cur=head;iter!=lst.end();cur=cur->next)
    cur->next=new  ListNode(*iter++);
   return head;
}
int main()
{
    Solution s;
    ListNode *l1=creat_linkedlist({2,3,4});
    ListNode *l2=creat_linkedlist({4,6,7});
    ListNode *ret=s.addTwoNumbers(l1,l2);
    for(ListNode *cur=ret;cur;cur=cur->next)
        cout<<cur->val<<"->";
    cout<<"\b\b"<<endl;

    return 0;
}
