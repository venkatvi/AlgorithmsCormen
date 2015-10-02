#include <iostream>
#include <math.h>
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
    void merge(ListNode* head1, ListNode* end1, ListNode* head2, ListNode* end2){
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;
        ListNode* headOfMergedList = NULL;
        ListNode* mergedList = NULL;

        while(temp1 != end1 && temp2 != end2){
          ListNode* nodeToAdd;
          if(temp1->val <= temp2->val){
            nodeToAdd = temp1;
            temp1 = temp1->next;
          }else{
            nodeToAdd = temp2;
            temp2 = temp2->next;
          }
          if(mergedList){
              mergedList->next = new ListNode(nodeToAdd->val);
              mergedList->next->next = NULL;
              mergedList = mergedList->next;
          }else{
              mergedList = new ListNode(nodeToAdd->val);
              mergedList->next = NULL;
              headOfMergedList  = mergedList;
          }
        }
        if(temp1 == end1){
            ListNode *a1, *a2;
            if (end1->val < temp2->val){
                a1 = end1;
                a2 = temp2;
            }else{
                a1 = temp2;
                a2 = end1;
            }
            if(!mergedList){
                headOfMergedList = new ListNode(a1->val);
                mergedList = headOfMergedList;
            } else{
                mergedList->next = new ListNode(a1->val);
                mergedList = mergedList->next;
            }
            mergedList->next = new ListNode(a2->val);
            mergedList = mergedList->next;

            temp2 = temp2->next;
            while(temp2 != end2 && temp2!=NULL){
                mergedList->next = new ListNode(temp2->val);
                temp2 = temp2->next;
                mergedList = mergedList->next;
            }
            if(temp2 == end2){
                mergedList->next = new ListNode(end2->val);
            }
        }
        else if(temp2 == end2){
            ListNode* a1, *a2;
            if (end2->val < temp1->val){
                a1 = end2;
                a2 = temp1;
            }else{
                a1 = temp1;
                a2 = end2;
            }
            if(!mergedList){
                headOfMergedList = new ListNode(a1->val);
                mergedList = headOfMergedList;
            } else{
                mergedList->next = new ListNode(a1->val);
                mergedList = mergedList->next;
            }
            mergedList->next = new ListNode(a2->val);
            mergedList = mergedList->next;
            
            temp1 = temp1->next;
            while(temp1 != end1 && temp1 != NULL){
                mergedList->next = new ListNode(temp1->val);
                temp1 = temp1->next;
                mergedList = mergedList->next;
            }
            if (temp1 == end1){
                mergedList->next = new ListNode(end1->val);
            }
        }
        mergedList = NULL;  
        
        ListNode*  p = headOfMergedList;
        ListNode* temp = head1;
        while(p != NULL){
            temp->val = p->val;
            p = p->next;
            temp = temp->next;
        }   
        return;
   }
   void mergeSort(ListNode* head, ListNode* end, int size){
       if (size <= 1) {  return; }
       int midIndex = floor(size/2);
       
       //find mid point
       ListNode* mid = head;
       int i=0;
       while(i< midIndex-1){
           mid = mid->next;
           i++;
       }
       mergeSort(head, mid, i+1);
       mergeSort(mid->next, end, size-(i+1));
       merge(head, mid, mid->next, end);
       
       return;
   }
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL) { return head; }
        ListNode* node = head;
        int n=0;
        while(node->next != NULL) {
            node = node->next;
            n++;
        }
        ListNode* end = node;


        mergeSort(head, end, n+1);
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
    int testInput[] = {3, 4, 2, 1};
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