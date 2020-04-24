#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode    *next;
    ListNode(int x):val(x),next(nullptr){}
};
class Solution
{
private:
    ListNode *ReverseNodesInGroup(ListNode *head,int k)
    {
        if(!head||!head->next||k<2) return   head;
        ListNode pre(0);
        pre.next=head;
        for (ListNode *front=&pre,*p_move=&pre;;front=head,p_move=head)//front为prehead节点，
        {
            for(int count=k;count>0;--count)
                if (!(p_move=p_move->next)) return pre.next;  // 移动k次到末尾,确定范围
            for (head=front->next;front->next!=p_move; )
            {//将头节点（front->next）移动到末尾（p_move)之后,即在p_move和p_move->next之间按照顺序插入节点
                //画图理解！！
                ListNode *next=front->next;
                front->next=next->next;
                next->next=p_move->next;
                p_move->next=next;
            }
                   
        }
        return pre.next;
    }
    ListNode *CreatLinkedList(std::initializer_list<int> lst)
    {
        auto iter=lst.begin();
        ListNode *head=lst.size()?new ListNode(*iter++):nullptr;
        for (ListNode *cur=head;iter!=lst.end();cur=cur->next)
        {
            cur->next=new ListNode(*iter++);
        }
        return head;
    }

public:
    ListNode *ReverseNodesInKGroup(ListNode *head,int k)
    {
        return ReverseNodesInGroup(head,k);
    }
    ListNode *CreatList(std::initializer_list<int> lst)
    {
        return CreatLinkedList(lst);
    }
   
};

int main()
{
    Solution s;
    ListNode *head=s.ReverseNodesInKGroup(s.CreatList({1,2,3,4,5,6,7,8}),3);
    for(ListNode *cur=head;cur;cur=cur->next)
    {
        std::cout<<cur->val;
        if(cur->next) cout<<"->";
    }
    std::cout<<"\b\b"<<std::endl;

    return 1;
}

