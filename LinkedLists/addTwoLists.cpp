#include <iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	if (!l1 && !l2) { return NULL; }
	if (!l1 ) { return l2; }
	if (!l2 ) { return l1; }
	ListNode *p = l1, *q = l2;
	ListNode *addedList = NULL, *newHead = NULL;
	int prevSum = 0;
	while(p && q) {
		if (p->val > 9 || q->val > 9) { cout << "Error: " << endl; }
		int curSum = p->val + q->val + prevSum;
		prevSum = curSum / 10;
		curSum = curSum % 10;

		ListNode* newNode  = new ListNode(curSum);
		if(!newHead){
			newHead = newNode;
			addedList = newNode;
		}else{
			addedList->next = newNode;
			addedList = newNode;
		}
		p=p->next;
		q=q->next;
	}
	cout << "Printing .... " << endl;
	ListNode* temp = newHead;
	if (temp) {
		cout << temp->val << endl;
		temp = temp->next;
	}
	cout << "----------------------" << endl;

	if (!p) {
		cout << " P null " << endl;
		while(q) {
			cout << "Q not null " << endl;
			int curSum = q->val + prevSum;
			prevSum = curSum / 10;
			curSum = curSum % 10;

			ListNode* newNode = new ListNode(curSum);
			cout << " Adding new node " << curSum << endl;
			if (!newHead) {
				newHead = newNode;
				addedList = newNode;
			}else{
				addedList->next = newNode;
				cout << " Adding new node to end of addedList" << endl;
			}
			q=q->next;
		}
	}
	cout << "Printing .... " << endl;
	temp = newHead;
	if (temp) {
		cout << temp->val << endl;
		temp = temp->next;
	}
	cout << "----------------------" << endl;
/*	if (!q) {
		while(p) {
			int curSum = p->val + prevSum;
			prevSum = curSum / 10;
			curSum = curSum % 10;

			ListNode* newNode = new ListNode(curSum);
			if (!newHead) {
				newHead = newNode;
				addedList = newNode;
			}else{
				addedList->next = newNode;
			}
			p=p->next;
		}
	}
*/
	if(prevSum){
		ListNode* newNode = new ListNode(prevSum);
		if (!newHead) {
			newHead = newNode;
			addedList = newNode;
		}else{
			addedList->next = newNode;
		}
	}

	return newHead;
}
int main(int argc, char** argv){
	ListNode* a = new ListNode(1);
	ListNode* b1 = new ListNode(9);
	ListNode* b2 = new ListNode(9);
	b1->next = b2;

	ListNode* newList = addTwoNumbers(a, b1);
	ListNode* p = newList;

	while(p){
		cout << p->val << endl;
		p = p->next;
	}
	
}
