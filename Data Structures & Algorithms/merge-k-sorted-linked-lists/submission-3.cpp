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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        int size = lists.size();
        while (size > 1) {
            for (int i = 0; i < size/2; ++i) 
                lists[i] = merge(lists[i], lists[size-1-i]);
            size = (size + 1) / 2;
        }
        return lists[0];
    }

    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode head{-1001, nullptr};
        ListNode * h = &head;
        while (a != nullptr && b != nullptr) {
            if (a->val < b->val) {
                h->next = a;
                a = a->next;
            } else {
                h->next = b;
                b = b->next;
            }
            h = h->next;
        }
        if (a != nullptr) h->next = a;
        if (b != nullptr) h->next = b;
        return head.next;
    }
};
