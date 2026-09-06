class Solution {
public:

    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != NULL)
                pq.push(lists[i]);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(!pq.empty()) {
            ListNode* x = pq.top();
            pq.pop();

            curr->next = x;
            curr = curr->next;

            if(x->next != NULL)
                pq.push(x->next);
        }

        return dummy->next;
    }
};