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
// class Solution {
// public:
//     ListNode* deleteMiddle(ListNode* head) {
//         ListNode* slow=head;
//         ListNode* fast=head;
//         if(fast->next==NULL) return NULL;
//         while(fast->next->next!=NULL && fast->next->next->next!=NULL){
//             slow=slow->next;
//             fast=fast->next->next;  
//         }
//         slow->next=slow->next->next;
//         return head;
//     }
// };


// class Solution {
// public:
//     ListNode* deleteMiddle(ListNode* head) {
//         if (head == NULL || head->next == NULL) return NULL;
//         ListNode* slow = head;
//         ListNode* fast = head;
//         ListNode* prev = NULL;
//         while (fast != NULL && fast->next != NULL) {
//             prev = slow;
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         prev->next = slow->next;
//         return head;
//     }
// };

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) return NULL;

        ListNode* slow = head, *fast = head;
        while (fast!=NULL && fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = NULL, *curr = head;
        while (curr != slow) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next; // jaise hi curr slow pr aay
                              // pre ke next ko curr ke next
        return head;
    }
};

