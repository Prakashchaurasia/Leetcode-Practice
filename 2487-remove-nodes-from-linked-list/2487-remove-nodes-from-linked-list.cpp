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
    ListNode* removeNodes(ListNode* head) {
        vector<int> h;
        ListNode* temp=head;
        while(temp!=NULL){
            h.push_back(temp->val);
            temp=temp->next;
        }
        int n=h.size();
        if(n==0) return NULL;
        vector<int> suffMax(h.size());
        suffMax[n-1]=h[n-1];
        for(int i=n-2;i>=0;i--){
            suffMax[i]=max(suffMax[i+1],h[i]);
        }
        ListNode* p=NULL;
        ListNode* ans = NULL;
        for(int i=0;i<n;i++){
            if(suffMax[i]==h[i]){
               if(p==NULL){
                 p= new ListNode(h[i]);
                 ans = p;
               }
               else{
                p->next = new ListNode(h[i]);
                p=p->next;
               }
            }
        }
        return ans;
    }
};