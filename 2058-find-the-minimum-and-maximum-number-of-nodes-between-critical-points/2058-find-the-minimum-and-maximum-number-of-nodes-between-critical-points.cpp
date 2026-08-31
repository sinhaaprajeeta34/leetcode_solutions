class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1;        // first critical point
        int last = -1;         // previous critical point
        int minDist = INT_MAX;

        int index = 0;

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {

            // First and last node cannot be critical
            if (prev != nullptr && curr->next != nullptr) {

                // Check critical point
                if ((curr->val > prev->val && curr->val > curr->next->val) ||
                    (curr->val < prev->val && curr->val < curr->next->val)) {

                    // First critical point
                    if (first == -1) {
                        first = index;
                    }

                    // Calculate distance from previous critical point
                    if (last != -1) {
                        minDist = min(minDist, index - last);
                    }

                    last = index;
                }
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        // Less than 2 critical points
        if (first == last) {
            return {-1, -1};
        }

        // Maximum distance = last critical - first critical
        int maxDist = last - first;

        return {minDist, maxDist};
    }
};