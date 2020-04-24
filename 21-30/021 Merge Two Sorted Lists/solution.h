#include <vector>

using std::vector;

using vecIter=vector<int>::iterator;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};
class Solution
{
public:
    ListNode *MergeTwoList(ListNode *l1,ListNode *l2)
    {
        ListNode *head=nullptr;
        ListNode **p;
        for (p=&head ;l1&&l2;p=&(*p)->next)
        {
            if (l1->val<l2->val)
            {
                *p=l1;
                l1=l1->next;           
            }    
            else
            {
                *p=l2;
                l2=l2->next;
            }       
        }  
        // l1==nullptr?cout<<1<<endl:cout<<2<<endl;

        *p=l1? l1 :l2;
        
        return head;         
    }
    ListNode *CreatLinkedList( vecIter beg,vecIter end)
{
    ListNode *head=beg==end? NULL:new ListNode(*beg++);
    for (ListNode *cur=head;beg!=end;cur=cur->next)
        cur->next=new ListNode(*beg++);
    return head;  
}
};

