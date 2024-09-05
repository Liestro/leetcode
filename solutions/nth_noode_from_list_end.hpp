#include "ForwardList.hpp"

#include <iostream>

using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* rightNode = head; 
        ListNode* leftNode = new ListNode(0, head);

        cout << "[";
        for (auto tmp = leftNode; tmp != nullptr; tmp = tmp->next) {
            cout << tmp->val << ", ";
        }
        cout << "]" << endl;

        for (int distance = 1; rightNode != nullptr; rightNode = rightNode->next) {
            cout << leftNode->val << endl;
            cout << rightNode << " " << distance << endl;
            if (distance >= n + 1) 
                leftNode = leftNode->next;
            else
                distance++;
        }

        auto tmpNode = leftNode->next;
        leftNode->next = tmpNode->next;
        if (tmpNode == head)
            head = head->next;
        if (tmpNode) delete tmpNode;

        return head;
    }
};