#include <cstddef>
#include <iostream>
#include <vector>
using std::vector;
using vecIter=vector<int> ::iterator;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode **del=&head,*iter=head;
        for(auto i=0;i<n;++i,iter=iter->next);
        for(;iter!=NULL;del=&((*del)->next),iter=iter->next);//

        *del=(*del)->next;//change value
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
    vector<int> vec1{1,2,4,5,6};
    vector<int> vec2{2,3,6};
    ListNode *head1=CreatLinkedList(vec1.begin(),vec1.end());
    ListNode *head2=CreatLinkedList(vec2.begin(),vec2.end());

    Solution s;
    ListNode *res1=s.removeNthFromEnd(head1,2);
    ListNode *res2=s.removeNthFromEnd(head2,2);


    PrintandClear(res1);
    PrintandClear(res2);
    return 1;

}