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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total = 0;
        
        ListNode *temp = head;
        while (temp != NULL) {
            total++;
            temp = temp->next;
        }
        int remove = total - n;
        ListNode *tp = head;
        ListNode *t = NULL;
        if (remove == 0) return head->next;
        while(remove--) {
            t = tp;
            tp = tp->next;
        }
        t->next = tp->next;
        delete(tp);
        return head;
    }
};

ListNode* buildList(int arr[], int size) {
    ListNode *head = new ListNode(arr[0]);
    ListNode *curr = head;
    for (int i = 1; i < size; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode *head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 2;

    ListNode *head = buildList(arr, 5);
    cout << "Before: "; printList(head);

    Solution sol;
    head = sol.removeNthFromEnd(head, n);
    cout << "After:  "; printList(head);

    return 0;
}