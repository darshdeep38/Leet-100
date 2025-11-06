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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // Min-heap based on node value
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        
        // Step 1: Push the head of each list into the min-heap
        for (auto node : lists) {
            if (node) pq.push(node);
        }
        
        // Step 2: Create a dummy head to build the merged list
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        // Step 3: Extract the smallest node and add its next to heap
        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();
            
            tail->next = smallest;
            tail = tail->next;
            
            if (smallest->next)
                pq.push(smallest->next);
        }
        
        // Step 4: Return merged list
        return dummy->next;
    }
};
