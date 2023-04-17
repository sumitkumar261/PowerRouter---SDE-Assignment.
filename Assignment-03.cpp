#include <stdio.h>
#include <stdlib.h>

// Including necessary header files
#include <bits/stdc++.h> 

// Using standard namespace
using namespace std;

// Defining the Node structure to represent a node in a linked list
struct Node {
    int value;
    Node *next;
    // Constructors to initialize the members of the structure
    Node() : value(0), next(nullptr) {}
    Node(int x) : value(x), next(nullptr) {}
    Node(int x, Node *next) : value(x), next(next) {}
};

// Function to find the middle node of a singly linked list
Node* middleNode(Node* head) {
    // If the linked list is empty or has only one node, return head
    if (head == NULL || head->next == NULL) return head;
    // If the linked list has only two nodes, return the second node
    if (head->next->next == NULL) return head->next;

    // Initializing slow and fast pointers
    Node* slow = head;
    Node* fast = head->next;

    // Move the slow pointer by one node and the fast pointer by two nodes
    // When the fast pointer reaches the end of the linked list, the slow pointer will be at the middle node
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) fast = fast->next;
        slow = slow->next;
    }

    // Return the middle node
    return slow;
}

// Function to insert a new node at the beginning of a linked list
void insertathead(Node*& head, int val) {
    // Create a new node
    Node* n = new Node(val);
    // Set the next pointer of the new node to the head of the linked list
    n->next = head;
    // Update the head pointer to point to the new node
    head = n;
}

// Main function
int main() {
    Node* head = NULL;

    // Ask the user to enter the number of elements in the linked list
    int n;
    cout << "Enter the number of elements in the linkedlist: ";
    cout << endl;
    // Read the input
    cin >> n;

    // Ask the user to enter the elements one by one and insert them at the beginning of the linked list
    cout << "Enter the elements one by one: " << endl;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        insertathead(head, a);
    }

    // Print all the elements in the linked list
    Node* temp = head;
    cout << "The elements in the linkedlist are: " << endl;
    while (temp != NULL) {
        cout << " " << temp->value;
        temp = temp->next;
    }

    // Call the middleNode function to find the middle node of the linked list
    Node* middle = middleNode(head);

    // If the linked list is empty or has only one node, middle will be NULL
    if (middle == NULL) {
        cout << endl << "Enter the valid number of elements." << endl;
    } else {
        // Print the value of the middle node
        cout << endl << "The middle element of the given linked list is: " << endl;
        cout << middle->value << endl;
    }

}