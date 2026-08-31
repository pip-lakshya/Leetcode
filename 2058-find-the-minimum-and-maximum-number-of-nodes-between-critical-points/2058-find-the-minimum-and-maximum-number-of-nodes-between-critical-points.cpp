class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        int pos = 1;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        int first = -1;
        int last = -1;
        int minDist = INT_MAX;
        
        while(curr->next != NULL) {
            
            ListNode* next = curr->next;
            
            // Check whether curr is a critical point
            if((curr->val > prev->val && curr->val > next->val) ||
               (curr->val < prev->val && curr->val < next->val)) {
                
                if(first == -1) {
                    // First critical point
                    first = pos;
                }
                else {
                    // Distance from previous critical point
                    minDist = min(minDist, pos - last);
                }
                
                last = pos;
            }
            
            prev = curr;
            curr = next;
            pos++;
        }
        
        // Fewer than 2 critical points
        if(first == -1 || first == last) {
            return {-1, -1};
        }
        
        int maxDist = last - first;
        
        return {minDist, maxDist};
    }
};