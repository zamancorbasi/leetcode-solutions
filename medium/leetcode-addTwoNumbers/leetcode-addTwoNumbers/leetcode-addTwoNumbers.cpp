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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;

        int carry = 0;

        while (l1 || l2) {
            int sum = carry;
            carry = 0;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            if (sum >= 10) {
                carry = 1;
                sum -= 10;
            }

            current->next = new ListNode(sum);
            current = current->next;

            cout << "Step result: " << current->val << endl;
        }

        if (carry) {
            current->next = new ListNode(carry);
            current = current->next;
            cout << "Final carry: " << current->val << endl;
        }

        return dummy->next;
    }
};

// Yardımcı fonksiyonlar
ListNode* createList(const vector<int>& nums) {
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;
    for (int num : nums) {
        current->next = new ListNode(num);
        current = current->next;
    }
    return dummy->next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Örnek: 342 + 465 = 807
    vector<int> num1 = { 2, 4, 3 }; // 342
    vector<int> num2 = { 5, 6, 4 }; // 465

    ListNode* l1 = createList(num1);
    ListNode* l2 = createList(num2);

    cout << "Input l1: ";
    printList(l1);
    cout << "Input l2: ";
    printList(l2);

    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    return 0;
}
