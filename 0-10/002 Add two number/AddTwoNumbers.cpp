#include <iostream>

using namespace std;

struct  ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

class Solution{
public:
    ListNode   *CreatList(std::initializer_list<int> lst){
        auto iter=lst.begin();
        ListNode *head=lst.size()?new ListNode(*iter++):nullptr;
        for(ListNode *cur=head;iter!=lst.end();cur=cur->next)
            cur->next=new ListNode(*iter++);
       
        return head;
    }
    ListNode *AddTwoNumbers(ListNode *l1,ListNode *l2)//输入两个已经逆序的数，从左至右为个十百位
    {
        int sum=0;
        ListNode *l3;
        ListNode **p=&l3;
        while(l1||l2||sum>0)
        {
            if(l1) {sum+=l1->val;l1=l1->next;}
            if(l2) {sum+=l2->val;l2=l2->next;}
            *p=new ListNode(sum%10);
            p=&(*p)->next;
            sum/=10;
        }
        return l3;
    }
} ;

int main(){
    Solution s;
    ListNode *l1=s.CreatList({1,2,3,4,5,6});
    ListNode *l2=s.CreatList({3,4,5,2,3,4,5,3});
    ListNode *l3=s.AddTwoNumbers(l1,l2);
    for(;l3;l3=l3->next) {cout<<l3->val<<"->";}

    return 1;
}