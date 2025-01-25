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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry) {
            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }

        return dummy.next;
    }
};
int main() {
    ListNode dummy1(0), dummy2(0);
    ListNode* ceva = &dummy1;
    ListNode* ceva2 = &dummy2;

    ceva->next = new ListNode(3);
    ceva = ceva->next;
    ceva->next = new ListNode(4);
    ceva = ceva->next;
    ceva->next = new ListNode(7);

    ceva2->next = new ListNode(3);
    ceva2 = ceva2->next;
    ceva2->next = new ListNode(6);
    ceva2 = ceva2->next;
    ceva2->next = new ListNode(2);

    cout << "Suma la cele doua este: ";
    Solution solution;
    ListNode* uite = solution.addTwoNumbers(dummy1.next, dummy2.next);

    while (uite != nullptr) {
        cout << uite->val << " ";
        uite = uite->next;
    }
    cout << endl;

    return 0;
}
