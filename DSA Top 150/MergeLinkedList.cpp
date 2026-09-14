#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == NULL) {
            return list2;
        }

        if (list2 == NULL) {
            return list1;
        }

        ListNode* result;

        if (list1->val < list2->val) {
            result = list1;
            result->next = mergeTwoLists(list1->next, list2);
        }
        else {
            result = list2;
            result->next = mergeTwoLists(list1, list2->next);
        }

        return result;
    }
};

int main() {
    // List 1: 1 -> 2 -> 4
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // List 2: 1 -> 3 -> 4
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    Solution obj;

    ListNode* result = obj.mergeTwoLists(list1, list2);

    cout << "Merged List: ";

    while (result != NULL) {
        cout << result->val;

        if (result->next != NULL)
            cout << " -> ";

        result = result->next;
    }

    cout << endl;

    return 0;
}