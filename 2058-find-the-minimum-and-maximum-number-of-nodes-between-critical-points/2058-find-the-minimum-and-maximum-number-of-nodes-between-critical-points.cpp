class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2,-1);
        if(head==NULL || head->next==NULL || head->next->next==NULL) return ans;
        long long l=2;
        ListNode* temp1=head;
        ListNode* temp2=head->next;
        ListNode* temp3=head->next->next;
        vector<long long> v;
        while(temp3!=NULL){
            if((temp2->val)>(temp3->val) && (temp2->val)>(temp1->val)){
                v.push_back(l);
            }
            if((temp2->val)<(temp3->val) && (temp2->val)<(temp1->val)){
                v.push_back(l);
            }
            l++;
            temp1=temp1->next;
            temp2=temp2->next;
            temp3=temp3->next;
        }
        if(v.size()<=1) return ans;
        int minDistance=v[1]-v[0];
        for(int i=0;i<v.size()-1;i++){
                if(v[i+1]-v[i]<minDistance) minDistance=v[i+1]-v[i];
        }
        int maxDistance=v[v.size()-1]-v[0];
        ans[0]=minDistance;
        ans[1]=maxDistance;
        return ans;
    }
};