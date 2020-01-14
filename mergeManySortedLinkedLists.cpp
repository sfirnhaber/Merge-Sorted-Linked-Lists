/*
 * Merge Many Sorted Linked Lists
 * By Sam Firnhaber
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    
    int lowestValue(vector<ListNode*>& lists) {
        int min = INT_MAX;
        int index;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL && lists[i]->val < min) {
                index = i;
                min = lists[i]->val;
            }
        }
        lists[index] = lists[index]->next;
        return min;
    }
    
    bool allNull(vector<ListNode*>& lists) {
        for (int i = 0; i < lists.size(); i++)
            if (lists[i] != NULL)
                return false;
        return true;
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0 || allNull(lists))
            return NULL;
        ListNode* head = new ListNode(lowestValue(lists));
        ListNode* ptr = head;
        while (!allNull(lists)) {
            ListNode* temp = new ListNode(lowestValue(lists));
            ptr->next = temp;
            ptr = temp;
        }
        return head;
    }
};