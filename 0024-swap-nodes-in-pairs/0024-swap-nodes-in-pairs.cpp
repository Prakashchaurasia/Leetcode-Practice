/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;
        ListNode* temp1=head;
        ListNode* temp2=head->next;
        ListNode* temp3=temp2->next;
        temp1->next=NULL;
        temp2->next=NULL;
        temp2->next=temp1;
        if(temp3==NULL){
            head=temp2;
            return head;
        }
        head=temp2;
        temp1->next=temp3;
        while(true){
            ListNode* prev=temp1;
            temp1=temp3;
            temp2=temp3->next;
            if(temp2==NULL){
                
                return head;
            }
            else if(temp2->next!=NULL){
                temp3=temp2->next;
                temp1->next=NULL;
                temp2->next=NULL;
                temp2->next=temp1;
                prev->next=temp2;
                temp1->next=temp3;
            }
            else{
                temp1->next=NULL;
                temp2->next=NULL;
                temp2->next=temp1;
                prev->next=temp2;
                return head;
            }
        }
        return head;
        
    }
};