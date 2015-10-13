#include <iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
};

ListNode* insertionSortList(ListNode* head) {
        if (!head) { return NULL; }
        ListNode* p = head, *sortedEnd = head;
        p = p->next; //head is trivially sorted.

        while(p){
            cout << "Element to sort: " << p->val << endl;
            ListNode* temp = p->next;
            ListNode *q = head, *prevQ = NULL; 
            bool isSorted = false;
            while(q) {
                cout << "Element to compare: " << q->val << endl;
                if (q->val > p->val && !isSorted){
                    cout << "Needs insertion" << endl;
                    p->next = q;

                    if(prevQ) {
                        prevQ->next = p;
                    }else{
                        head = p;
                    }

                    sortedEnd->next = temp;
                    p = temp;

                    isSorted = true;
                }else{
                    cout << "Noop " << endl;
                    if (isSorted || q == temp) {
                        cout << "IsSorted:" << isSorted << endl;
                        cout << "q might have met temp" << endl;
                        sortedEnd = prevQ;
                        break;
                    }
                }
                prevQ = q;
                q=q->next;
		if (p && q && prevQ && sortedEnd){
                	cout << " p: " << p->val << " q:" << q->val  << " prevQ: " << prevQ->val << " sortedEnd: " << sortedEnd->val <<  endl;
		}
                if (!temp) {
                    cout << " tmp: NULL" << endl;
                }else{
                    cout << " tmp: " << temp->val << endl;
                }
                if (!q && q == temp){
                    sortedEnd = prevQ;
                }
            }
            if (p && p != temp){
		cout << "Incrementing p" << endl;
                p = p->next;
            }
            if (p) {
                cout << " pOut: " << p->val << endl;
            }else{
                cout << " pOut: NULL" << endl;
            }
        }
        return head;
 }

int main(int argc, char** argv){
	ListNode* b1 = new ListNode(1);
	ListNode* b2 = new ListNode(1);
	b1->next = b2;

	ListNode* newList = insertionSortList(b1);
	ListNode* p = newList;
	while(p){
		cout << p->val << endl;
		p = p->next;
	}
}
	
