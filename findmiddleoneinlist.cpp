#include <iostream>

// Node structure for a linked list
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Function to find the middle element in a linked list
Node* findMiddleElement(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;  // Empty list or list with only one element
    }

    Node* slowPointer = head;
    Node* fastPointer = head;

    // Move the fast pointer two steps at a time and the slow pointer one step at a time
    while (fastPointer != nullptr && fastPointer->next != nullptr) {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
    }

    return slowPointer;
}

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    // Finding the middle element
    Node* middleElement = findMiddleElement(head);

    // Displaying the middle element
    std::cout << "Middle Element: " << middleElement->data << std::endl;

    return 0;
}
