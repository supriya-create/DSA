#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoSortedList(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        if (l1->val <= l2->val) {
            l1->next = mergeTwoSortedList(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoSortedList(l1, l2->next);
            return l2;
        }
    }

    ListNode* partitionAndMerge(int start, int end,
                                vector<ListNode*>& lists) {
        if (start > end) {
            return NULL;
        }

        if (start == end) {
            return lists[start];
        }

        int mid = start + (end - start) / 2;

        ListNode* L1 = partitionAndMerge(start, mid, lists);
        ListNode* L2 = partitionAndMerge(mid + 1, end, lists);

        return mergeTwoSortedList(L1, L2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();

        if (k == 0) {
            return NULL;
        }

        return partitionAndMerge(0, k - 1, lists);
    }
};

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;

        if (head->next != NULL)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main() {

    // List 1: 1 -> 4 -> 5
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    // List 2: 1 -> 3 -> 4
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    // List 3: 2 -> 6
    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode*> lists = {l1, l2, l3};

    Solution obj;

    ListNode* result = obj.mergeKLists(lists);

    cout << "Merged List: ";
    printList(result);

    return 0;
}