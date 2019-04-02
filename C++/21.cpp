#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print_ll(ListNode* lt) {
	if (lt == nullptr)
		return;
	cout << lt->val;
	for (lt = lt->next; lt; lt = lt->next) {
		cout << "->" << lt->val;
	}
	cout << endl;
}


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;

		ListNode *p1 = l1, *p2 = l2;		    
		ListNode *tmp = nullptr,  *pre = nullptr;
		ListNode *head = l1->val <= l2->val ? l1 : l2;
		auto inser_after = [](ListNode* pre, ListNode** node) {
			ListNode* next = pre->next;
			pre->next = (*node);
			ListNode* tmp = (*node)->next;
			(*node)->next = next;
			*node = tmp;
		};

		/* 1 2 4 */
		/* 1 3 4 */
		while (p1 and p2) {
			if (p1->val >= p2->val) {
				pre = p2;
				p2 = p2->next;
			} else if (p1->val < p2->val) {
				if (pre == nullptr) {
					tmp = p1->next;
					p1->next = p2;
					head = p1;
					p1 = tmp;
				} 
				else {
					inser_after(pre, &p1);
					print_ll(head);
				}
			}
		}

		if (p2 == nullptr) 
			pre->next = p1;
		return head;
    }
};

int main(void) {
	
	ListNode *h = new ListNode(1);
	ListNode *head = h;
	h->next = new ListNode(2);
	h = h->next;
	h->next = new ListNode(4);

	ListNode *h1 = new ListNode(1);
	ListNode *head1 = h1;
	h1->next = new ListNode(3);
	h1 = h1->next;
	h1->next = new ListNode(4);

	print_ll(head);
	print_ll(head1);

	ListNode* r = Solution().mergeTwoLists(head, head1);
	print_ll(r);

	return 0;
}
