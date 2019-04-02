#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <unordered_set>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == nullptr)
			return nullptr;

		ListNode* prh = head, *pf = head;
		int i = 0;
		for (; pf && i < n - 1; ++i, pf = pf->next);

		if (i < n - 1)
			return prh;

		ListNode* pa = head, *pre = head;
		while(pf->next) {
			pf = pf->next;
			pre = pa;
			pa = pa->next;
		}

		if (pa == pre) {
			return pa->next;
		} 
		else {
			pre->next = pa->next;
		}
		return prh;
    }
};

int main(void) {

	ListNode* lt = new ListNode(1);
	ListNode* hd = lt;
	lt->next = new ListNode(2);
	lt = lt->next;
	lt->next = new ListNode(3);
	lt = lt->next;
	lt->next = new ListNode(4);
	lt = lt->next;
	lt->next = new ListNode(5);

	for (ListNode* p = Solution().removeNthFromEnd(hd, 2); p; p = p->next) {
		cout << p->val << endl;
	}
	
	return 0;
}

