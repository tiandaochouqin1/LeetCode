#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using vecIter=std::vector<int>::iterator;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};
class Solution
{
public:
    ListNode *Merge2Lists(ListNode *l1,ListNode *l2)
    {
        ListNode    *head=nullptr,**p=&head;
        for ( ; l1&&l2; p=&(*p)->next)
            if (l1->val>l2->val)  {   *p=l2;  l2=l2->next; }
            else { *p=l1;  l1=l1->next; }

        *p=l1?l1:l2;
        return head; 
    }

    using vecNodeCIter=vector<ListNode *>::const_iterator;
    ListNode *mergeLists(vecNodeCIter beg,vecNodeCIter end)
    {
        if (beg==end) return NULL;
        else if(std::distance(beg,end)==1) return *beg;
        else if(std::distance(beg,end)==2) return Merge2Lists(*beg,*std::next(beg));
        else return Merge2Lists(mergeLists(beg,beg+std::distance(beg,end)/2),mergeLists(beg+std::distance(beg,end)/2,end));
        
    }

    ListNode *CreatLinkedList(vector<int> v1)
    {
        vector<int>::iterator beg=v1.begin(),end=v1.end();

        ListNode *head=beg==end? NULL:new ListNode(*beg++);
        for (auto *cur=head;beg!=end; cur=cur->next) {
            cur->next=new ListNode(*beg++); }
        return head;        
    }
    void Print(ListNode *head)
    {
        while(head)
        {   cout<<head->val;
            if(head->next) cout<<"->";
            ListNode *del=head;
            head=head->next;
            delete del;
        }
    }

    ListNode *MergerKLists(vector<ListNode *> &lists)
    {
        return mergeLists(lists.cbegin(),lists.cend());
    }
};