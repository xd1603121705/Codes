#include <iostream>

using namespace std;

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = nullptr;
        length = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= length) {
            return -1;
        }
        ListNode* curr = head;
        while (index--) {
            curr = curr->next;
        }
        return curr->val;
    }

    /** Add a node of value val before the first element of the linked list.
      * After the insertion, the new node will be the first node of the linked list.
      */
    void addAtHead(int val) {
        ListNode *node = new ListNode(val);
        node->next = head;
        head = node;
        length++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *node = new ListNode(val);
        ListNode* curr = head;
        if (curr == nullptr) {
            head = node;
        }
        else {
            while (curr->next) {
                curr = curr->next;
            }
            curr->next = node;
        }
        length++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index
      * equals to the length of linked list, the node will be appended to the end of
      * linked list. If index is greater than the length, the node will not be inserted.
      */
    void addAtIndex(int index, int val) {
        ListNode* curr = head;
        if (index > length) {
            return;
        }
        ListNode* node = new ListNode(val);
        if (index == 0) {
            node->next = head;
            head = node;
        }
        else {
            curr = head;
            while (--index) {
                curr = curr->next;
            }
            node->next = curr->next;
            curr->next = node;
        }
        length++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (head == nullptr || index >= length) {
            return;
        }
        if (index == 0) {
            head = head->next;
        }
        else {
            ListNode* prev = head;
            while (--index) {
                prev = prev->next;
            }
            prev->next = prev->next->next;
        }
    }
    private:
    struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
    ListNode* head;
    int length;
};

int main()
{
    MyLinkedList *linkedList = new MyLinkedList();
    linkedList->addAtHead(1);
    linkedList->addAtTail(3);
    linkedList->addAtIndex(1, 2);  // linked list becomes 1->2->3
    cout << linkedList->get(1) << endl;            // returns 2
    linkedList->deleteAtIndex(1);  // now the linked list is 1->3
    cout << linkedList->get(1) << endl;            // returns 3
}
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
