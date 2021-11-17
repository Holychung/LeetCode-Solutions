// Time:  O(n)
// Space: O(1)

class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        auto prev = head;
        int l = 2;
        while (prev->next) {
            auto curr = prev;
            int cnt = 0;
            for (int _ = 0; _ < l && curr->next; ++_, ++cnt, curr = curr->next);
            ++l;
            if (cnt % 2) {
                prev = curr;
                continue;
            }
            curr = prev->next;
            ListNode *last = nullptr;
            for (int _ = 0; _ < cnt; ++_) {
                auto nxt = curr->next;
                curr->next = last;
                last = curr;
                curr = nxt;
            }
            auto tail = prev->next;
            prev->next = last;
            tail->next = curr;
            prev = tail;
        }
        return head;
    }
};