#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::cin;
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
        for (p=&head ;l1&&l2;p=&l1->next)
        {  if (l1->val<l2->val){ *p=l1; l1=l1->next;  }    
            else {  *p=l2; l2=l2->next; }   }  
        // l1==nullptr?cout<<1<<endl:cout<<2<<endl;
        *p=l1? l1 :l2;
        return head;         
    }
};

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

ListNode *CreatLinkedList( vecIter beg,vecIter end)
{
    ListNode *head=beg==end? NULL:new ListNode(*beg++);
    for (ListNode *cur=head;beg!=end;cur=cur->next)
        cur->next=new ListNode(*beg++);
    return head;  
}

int main()
{
    Solution s;
    vector<int> vec1{1,2,3,4,9},vec2{0,2,3,6,7};
    ListNode *l1=CreatLinkedList(vec1.begin(),vec1.end());
    
    ListNode *l2=CreatLinkedList(vec2.begin(),vec2.end());

    ListNode *ll=s.MergeTwoList(l1,l2);
    // PrintandClear(l1);
    // PrintandClear(l2);
    PrintandClear(ll);
    return 0;
}
