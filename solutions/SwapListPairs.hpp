#pragma once

#include "ForwardList.hpp"

namespace swap_list_pairs {

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        auto newHead = head->next;
        head->next = swapPairs(head->next->next);
        newHead->next = head;

        return newHead;
    }
};

bool test() {
    ListNode* head = new ListNode(1);
    auto tmp = head;

    for (int i = 2; i <= 4; ++i) {
        tmp->next = new ListNode(i);
        tmp = tmp->next;
    }

    Solution sol;
    sol.swapPairs(head);

    return true;
}

}