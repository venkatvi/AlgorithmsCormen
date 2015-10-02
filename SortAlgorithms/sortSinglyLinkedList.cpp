#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
}; 

class Solution {
private:
    ListNode* partition(ListNode* head, ListNode* end){
        //quicksort (A, p, r)
        // i = p-1
        auto i = -1;
        ListNode* curINode = NULL;
        
        //j=p, cur is equivalent of j, hiNode of r
        auto cur = head;
        auto hiNode = end;
        
        // while j<= r-1 == cur->next != hiNode
        while(cur  != hiNode) //checking if penultimate node
        {
            // if A[j] <= A[r]
            if (cur->val <= hiNode->val){
                // increment i
                i++;
                if (i == 0){
                    curINode = head;
                }else{
                    curINode = curINode->next;
                }
                //swap A[i], A[j]
                swap(curINode->val, cur->val);
            }
            cur = cur->next;
        }
        if (i==-1){
            curINode = head;
        }
        // Swap A[i+1] with A[r]
        swap(curINode->next->val, hiNode->val);
        //return i+1 , in our case return A[i+1]
        return curINode;
    }
    void quickSort(ListNode* head, ListNode* end)
    {
        if( head == end) { return;}
        if (end->next == head) { return; }
        cout << "Head:" << head->val << " End:" << end->val << endl;
        auto prevToPivotNode = partition(head, end);
        
        cout << "Prev To Pivot Node found: " << prevToPivotNode->val << endl;
        if (head != prevToPivotNode){
            quickSort(head, prevToPivotNode);
        }
        if (prevToPivotNode->next != NULL && prevToPivotNode->next->next != NULL)
        {
            ListNode* nextToPivotNode = prevToPivotNode->next->next;
            quickSort(nextToPivotNode, end);   
        }   
    }
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL) { return head; }
        ListNode* node = head;
        while(node->next != NULL) {
            node = node->next;
        }

        quickSort(head, node);
        return head;
    }
    void printList(ListNode* head){
        ListNode* node  = head;
        
        cout << "Starting Print........" << endl;
        while(node->next != NULL){
            cout << node->val << endl;
            node = node->next;
        }   
        cout << node->val << endl;
        cout << "Ending Print........." << endl; 
    }
};
int main(int argc, char* argv[]){
    int testInput[] = {1, 2, 3, 4};
    int size = 4;
    ListNode* head = NULL;
    ListNode* prevNode = NULL;
    for(int i=0; i<size; i++){
        ListNode *node = new ListNode(testInput[i]);
        if(prevNode != NULL){
            prevNode->next = node;
        }else{
            head = node;
        }
        prevNode = node;
    }
    prevNode->next = NULL;
    
    Solution s;
    s.printList(head);
    
    head = s.sortList(head);
    s.printList(head);
}