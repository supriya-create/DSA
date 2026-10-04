#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        // Check if k nodes are available
        ListNode* temp = head;

        for(int i = 0; i < k; i++) {
            if(temp == NULL)
                return head;

            temp = temp->next;
        }

        // Reverse k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;

        for(int i = 0; i < k; i++) {

            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        // Connect current group to next group
        head->next = reverseKGroup(curr, k);

        return prev;
    }
};

// Print linked list
void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->val;

        if(head->next != NULL)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main() {

    // Create linked list:
    // 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);

    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    cout << "Original List: ";
    printList(head);

    Solution obj;

    head = obj.reverseKGroup(head, k);

    cout << "After reversing in groups of " << k << ": ";
    printList(head);

    return 0;
}